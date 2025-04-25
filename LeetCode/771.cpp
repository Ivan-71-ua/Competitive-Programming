
#include <bits/stdc++.h>

class Solution {
public:
	int numJewelsInStones(std::string jewels, std::string stones) {
		std::unordered_map<char, int> jew;
		std::unordered_map<char, int> stone;
		int res = 0;
		for (int i = 0; i < jewels.size(); i++)
		{
			jew[jewels[i]]++;
		}
		for (int i = 0; i < stones.size(); i++)
		{
			stone[stones[i]]++;
		}
		for (auto now: jew)
		{
			res += stone[now.first];
		}
		return res;
	}
};