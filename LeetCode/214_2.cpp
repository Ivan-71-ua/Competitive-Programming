#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>



class Solution {
	std::vector<int> pref_fun(std::string sub) {
		int n = sub.size();
		std::vector<int> pref(n);
		for (int i = 1; i < n; i++)
		{
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
	int max_palindrome(std::string str) {
		int n = str.size();
		std::vector<int> pref = pref_fun(str);
		std::string patern = str;
		std::reverse(str.begin(), str.end());
		int j_c = 0 ;
		for (int i = 0; i < n; i++)
		{
			while (j_c > 0 && str[i] != patern[j_c]) {
				j_c = pref[j_c - 1];
			}
			if (str[i] == patern[j_c])
				j_c++;
		}
		return j_c;
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

int main() {
	Solution asn;
	asn.shortestPalindrome("ababbbabbaba");
}