#include <bits/stdc++.h>

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
   bool isPalindrome(int x) {
		if(x < 0)
			return false;
		std::string s = std::to_string(x);
		for (int i = 0, j = s.size()-1; i <= j; i++, j--)
		{
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
};

int main() {
	Solution ans;
	ans.isPalindrome(121);
}