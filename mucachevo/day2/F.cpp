#include <bits/stdc++.h>

std::vector<int> build_suffix_array(const std::string &s) {
	int n = s.size();
	std::vector<int> p(n), c(n), cnt(std::max(256, n), 0);
	for (int i = 0; i < n; i++) cnt[s[i]]++;
	for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]]) classes++;
		c[p[i]] = classes - 1;
	}
	std::vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; h++) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) pn[i] += n;
		}
		std::fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			int mid1 = (p[i] + (1 << h)) % n;
			int mid2 = (p[i - 1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}

int lower_bound(const std::string &s, const std::string &t, const std::vector<int> &suffix_array) {
	int l = 0, r = suffix_array.size();
	while (l < r) {
		int m = (l + r) / 2;
		if (s.compare(suffix_array[m], t.size(), t) < 0) l = m + 1;
		else r = m;
	}
	return l;
}

int upper_bound(const std::string &s, const std::string &t, const std::vector<int> &suffix_array) {
	int l = 0, r = suffix_array.size();
	while (l < r) {
		int m = (l + r) / 2;
		if (s.compare(suffix_array[m], t.size(), t) <= 0) l = m + 1;
		else r = m;
	}
	return l;
}

std::vector<int> process_queries(const std::string &s, const std::vector<std::string> &queries) {
	std::vector<int> suffix_array = build_suffix_array(s);
	std::vector<int> results;
	for (const auto &t : queries) {
		int lb = lower_bound(s, t, suffix_array);
		int ub = upper_bound(s, t, suffix_array);
		results.push_back(ub - lb);
	}
	return results;
}

int main() {
	std::string s;
	std::cin >> s;
	int q;
	std::cin >> q;
	std::vector<std::string> queries(q);
	for (int i = 0; i < q; i++) {
		std::cin >> queries[i];
	}
	std::vector<int> results = process_queries(s, queries);
	for (int res : results) {
		std::cout << res << "\n";
	}
	return 0;
}
