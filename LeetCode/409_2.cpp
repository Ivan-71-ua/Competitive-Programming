#include <bits/stdc++.h>



const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int longestPalindrome(std::string s) {
		std::vector<int> alph('z' + 1);
		for (int i = 0; i < s.size(); i++)
		{
			alph[s[i]]++;
		}
		int even = 0;
		int odd =0;
		for (int i = 'A'; i <= 'z'; i++)
		{
			even += alph[i] & (~1);
			odd |= alph[i] & 1;
		}
		
		return even + odd;
	}
};


