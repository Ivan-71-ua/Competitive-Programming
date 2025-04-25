#include <bits/stdc++.h>



class Solution {
public:
	int findTheLongestSubstring(std::string s) {
		std::vector<int> maskes(32, -2);
		maskes[0] = -1;
		int mask = 0;
		int maxs = 0;
		for (int ch = 0; ch < s.size(); ch++)
		{
			if(s[ch] == 'a') {
				mask ^= 1;
			}else if(s[ch]  == 'e') {
				mask ^= 2;
			} else if(s[ch]  == 'i') {
				mask ^= 4;
			} else if(s[ch]  == 'o') {
				mask ^= 8;
			} else if(s[ch]  == 'u') {
				mask ^= 16;
			}
			int prev = maskes[mask];
			if(prev == -2) {
				maskes[mask] = ch;
			} else {
				maxs = std::max(maxs, ch - prev);
			}
		}
		return maxs;
	}
};