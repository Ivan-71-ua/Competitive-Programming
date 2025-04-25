#include <bits/stdc++.h>


class Solution {
	std::vector<int> pref_fun(const std::string& sub) {
		int n = sub.size();
		std::vector<int> pref(n);
		for (int i = 1; i < n; i++) {
			int j = pref[i - 1];
			while (j > 0 && sub[i] != sub[j]) {
				j = pref[j - 1];
			}
			if (sub[i] == sub[j])
				j++;
			pref[i] = j;
		}
		return pref;
	}

	int max_palindrome(const std::string& str) {
		int n = str.size();
		std::string reversed_str = str;
		std::reverse(reversed_str.begin(), reversed_str.end());
		std::string new_str = str + "#" + reversed_str;
		std::vector<int> pref = pref_fun(new_str);
		return pref.back();
	}

public:
	std::string shortestPalindrome(std::string s) {
		int len_max_sub_palindrom = max_palindrome(s);
		int need_add = s.size() - len_max_sub_palindrom;
		std::string res;
		int k = s.size() - 1;
		while (need_add--) {
			res += s[k--];
		}
		res += s;
		return res;
	}
};
