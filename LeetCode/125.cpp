#include <bits/stdc++.h>


class Solution {
public:
   bool isPalindrome(std::string s) {
		std::string st = "";
		for (int i = 0; i < s.size(); i++)
		{
			if(std::isalnum(s[i])) {
				if(std::isalpha(s[i])) {
					char c = std::tolower(s[i]);
					st.push_back(c);
				} else {
					st.push_back(s[i]);
				}
				
			}
		}
		
		for (int i = 0, j = st.size() -1; i < st.size() / 2; i++, j--)
		{
			if(st[i] != st[j]) {
				return false;
			}
		}
		return true;
		}
};

int main() {
	Solution ans;
	std::string s = "A man, a plan, a canal: Panama";
	ans.isPalindrome(s);
}