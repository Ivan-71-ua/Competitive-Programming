#include <bits/stdc++.h>



class Solution {
public:
	int maxScoreSightseeingPair(std::vector<int>& values) {
		int n = values.size();
		int cur_max = values[0] - 1;
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			res = std::max(res, cur_max + values[i]);
			cur_max = std::max(cur_max - 1, values[i] - 1);
		}
		return res;
	}
};