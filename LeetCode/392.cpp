#include <bits/stdc++.h>

class Solution {
public:
   bool isSubsequence(std::string s, std::string t) {
		int j = 0;
		for (int i = 0; i < t.size() && j < s.size(); i++)
		{
			if(t[i] == s[j]) {
				j++;
			}
		}
		if(j == s.size())
			return true;
		return false;
	}
};

int main() {
	Solution ans;
	ans.isSubsequence("abc", "ahbgdc");
}