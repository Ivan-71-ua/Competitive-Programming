#include <bits/stdc++.h>


class Solution {
	std::unordered_map<int, std::vector<int>> pairs;
	std::vector<int> ans;
public:
	std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
		for (int i = 0; i < adjacentPairs.size(); i++)
		{
			pairs[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
			pairs[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
		}
		int cur = -1;
		int prev = -1;
		for (auto now: pairs)
		{
			if(now.second.size() == 1) {
				prev = now.first;
				cur = now.second[0];
				ans.push_back(prev);
				ans.push_back(cur);
				break;
			}
		}
		while(ans.size() <= adjacentPairs.size()) {
			auto neigbor = pairs[cur];
			if(neigbor[0] == prev) {
				ans.push_back(neigbor[1]);
			} else {
				ans.push_back(neigbor[0]);
			}
			prev = cur;
			cur = ans.back();
		}
	}
};