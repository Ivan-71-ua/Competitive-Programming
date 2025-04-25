#include <bits/stdc++.h>


std::vector<int> build_suffix_array(const std::string &s) {
	int n = s.size();
	std::vector<int> p(n), c(n), cnt(std::max(256, n), 0);

	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}
	for (int i = 1; i < 256; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		p[--cnt[s[i]]] = i;
	}

	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]]) {
			classes++;
		}
		c[p[i]] = classes - 1;
	}

	std::vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; h++) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) {
					pn[i] += n;
			}
		}

		std::fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++) {
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i < classes; i++) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			p[--cnt[c[pn[i]]]] = pn[i];
		}

		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			int mid1 = (p[i] + (1 << h)) % n;
			int mid2 = (p[i - 1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) {
					classes++;
			}
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}

	return p;
}

std::vector<int> build_lcp_array(const std::string &s, const std::vector<int> &suffix_array) {
	int n = s.size();
	std::vector<int> rank(n), lcp(n - 1, 0);

	for (int i = 0; i < n; i++) {
		rank[suffix_array[i]] = i;
	}

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i] > 0) {
			int j = suffix_array[rank[i] - 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
					k++;
			}
			lcp[rank[i] - 1] = k;
			if (k > 0) {
					k--;
			}
		}
	}

	return lcp;
}

int main() {
	std::string s;
	std::cin >> s;
	s += "$";

	std::vector<int> suffix_array = build_suffix_array(s);

	std::vector<int> lcp_array = build_lcp_array(s, suffix_array);

	for (int i = 1; i < suffix_array.size(); i++) {
		std::cout << suffix_array[i] << " ";
	}
	std::cout << "\n";

	for (int i = 1; i < lcp_array.size(); i++) {
		std::cout << lcp_array[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
