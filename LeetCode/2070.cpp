#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
		std::sort(items.begin(), items.end());
		std::vector<std::pair<int, int>> idx;
		for (int i = 0; i < queries.size(); i++)
		{
			idx.push_back({queries[i], i});
		}
		std::sort(idx.begin(), idx.end());
		std::vector<int> ans(queries.size());
		int maxs = 0;
		int j = 0;
		for(auto [x, i]: idx) {
			while(j < items.size() && items[j][0] <=  x) {
				maxs = std::max(maxs, items[j][1]);
				j++;
			}
			ans[i] = maxs;
		}
		return ans;
	}
};