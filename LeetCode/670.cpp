

#include <bits/stdc++.h>


class Solution {
public:
	int maximumSwap(int num) {
		std::string maxs, cur;
		cur = maxs = std::to_string(num);
		for (int i = 0; i < cur.size(); i++)
		{
			for (int j = i + 1; j < cur.size(); j++)
			{
				std::swap(cur[i], cur[j]);
				maxs = std::max(maxs, cur);
				std::swap(cur[i], cur[j]);
			}
		}
		return std::stoi(maxs);
	}
};