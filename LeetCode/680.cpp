#include <bits/stdc++.h>




class Solution {
	bool isPdm(int st, int fn, std::string s) {
		for (int i = st, j = fn; i < j; i++, j--)
		{
			if(s[i]!= s[j])
				return false;
		}
		return true;
	}

public:
   bool validPalindrome(std::string s) {
      if(s.size() <= 2)
			return true;
		for (int i = 0, j = s.size() -1; i < j; i++, j--)
		{
			if(s[i] != s[j]) {
				return isPdm(i, j - 1, s) || isPdm(i + 1, j, s);
			}
		}
		return true;
	}
	
};

int main () {
	Solution ams;
	ams.validPalindrome("deeee");
}