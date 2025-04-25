#include <bits/stdc++.h>


class Solution {
	std::unordered_map<int, std::vector<int>> pairs;
	std::unordered_map<int, int> used;
	std::vector<int> ans;
	void DFS(int start) {
		ans.push_back(start);
		used[start] = 1;
		for (auto now: pairs[start])
		{
			if(!used[now]) {
				DFS(now);
			}
		}
	}
public:
	std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
		for (int i = 0; i < adjacentPairs.size(); i++)
		{
			pairs[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
			pairs[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
		}
		int st = -1;
		for (auto now: pairs)
		{
			if(now.second.size() == 1) {
				st = now.first;
				break;
			}
		}
		DFS(st);
		return ans;
	}
};