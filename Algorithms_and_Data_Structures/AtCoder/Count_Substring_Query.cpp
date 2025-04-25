#include <bits/stdc++.h>

std::vector<int> pref_fun(const std::string& s) {
	std::vector<int> pref(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pref[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pref[j - 1];
		}
		if (s[i] == s[j])
			j++;
		pref[i] = j;
	}
	return pref;
}

int KMP_serch_modify(const std::string& sub, const std::string& text) {
	std::vector<int> pref_sub = pref_fun(sub);
	int j = 0;
	int count = 0;
	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != sub[j]) {
			j = pref_sub[j - 1];
		}
		if (text[i] == sub[j]) {
			j++;
		}
		if (j == sub.size()) {
			count++;
			j = pref_sub[j - 1];
		}
	}
	return count;
}

int main() {
	std::string text;
	int q;
	std::cin >> text >> q;
	for (int i = 0; i < q; i++) {
		std::string sub;
		std::cin >> sub;
		std::cout << KMP_serch_modify(sub, text) << '\n';
	}
	return 0;
}
