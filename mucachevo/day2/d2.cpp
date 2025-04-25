#include <bits/stdc++.h>

std::vector<long long> build_suffix_array(const std::string &s) {
	long long n = s.size();
	std::vector<long long> p(n), c(n), cnt(std::max(256LL, n), 0);
	for (long long i = 0; i < n; i++) cnt[s[i]]++;
	for (long long i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
	for (long long i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	long long classes = 1;
	for (long long i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]]) classes++;
		c[p[i]] = classes - 1;
	}
	std::vector<long long> pn(n), cn(n);
	for (long long h = 0; (1LL << h) < n; h++) {
		for (long long i = 0; i < n; i++) {
			pn[i] = p[i] - (1LL << h);
			if (pn[i] < 0) pn[i] += n;
		}
		std::fill(cnt.begin(), cnt.begin() + classes, 0);
		for (long long i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for (long long i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
		for (long long i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (long long i = 1; i < n; i++) {
			long long mid1 = (p[i] + (1LL << h)) % n;
			long long mid2 = (p[i - 1] + (1LL << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}

std::vector<long long> build_lcp_array(const std::string &s, const std::vector<long long> &suffix_array) {
	long long n = s.size();
	std::vector<long long> rank(n), lcp(n - 1, 0);
	for (long long i = 0; i < n; i++) rank[suffix_array[i]] = i;
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		if (rank[i] > 0) {
			long long j = suffix_array[rank[i] - 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
			lcp[rank[i] - 1] = k;
			if (k > 0) k--;
		}
	}
	return lcp;
}

long long count_distinct_substrings(const std::string &s) {
	long long n = s.size();
	std::vector<long long> suffix_array = build_suffix_array(s);
	std::vector<long long> lcp_array = build_lcp_array(s, suffix_array);

	long long total_substrings = 0;
	for (long long i = 0; i < n; i++) {
		total_substrings += (n - suffix_array[i]);
		if (i > 0) {
			total_substrings -= lcp_array[i - 1];
		}
	}

	return total_substrings;
}

int main() {
	std::string s;
	std::cin >> s;

	long long result = count_distinct_substrings(s);
	std::cout << result << "\n";

	return 0;
}
