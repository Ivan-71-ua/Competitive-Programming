#include <bits/stdc++.h>

class Solution {
public:
   std::string longestPalindrome(std::string s) {
		std::string ans;
		for (int i = 0; i < s.size(); i++)
		{
			int r = i;
			int l = i;
			while(l >= 0 && r < s.size() && s[r] == s[l]) {
				if(ans.size() < r - (l -1)) {
					ans = s.substr(l, r - (l - 1));
				}
				l--;
				r++;
			}
			r = i;
			l = i + 1;
			while(l >= 0 && r < s.size() && s[r] == s[l]) {
				if(ans.size() < r - (l -1)) {
					ans = s.substr(l, r - (l - 1));
				}
				l--;
				r++;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.longestPalindrome("bb");
}