#include <bits/stdc++.h>


class Solution {
public:
	int shortestPathLength(std::vector<std::vector<int>>& graph) {
		int n = graph.size();
		int all_visit = (1 << n) - 1;
		std::queue<std::vector<int>> q;
		std::set<std::pair<int, int>> visited;
		for (int i = 0; i < n; i++)
		{
			int cur_mask = 1 << i;
			q.push({0, i, cur_mask});
			visited.insert({i, cur_mask});
		}
		while(!q.empty()) {
			int dist = q.front()[0];
			int idx = q.front()[1];
			int cur_mask = q.front()[2];
			q.pop();
			if(cur_mask == all_visit)
				return dist;
			for (auto to: graph[idx])
			{
				int to_mask = cur_mask | (1 << to);
				if(!visited.count({to, to_mask})) {
					visited.insert({to, to_mask});
					q.push({dist + 1, to, to_mask});
				}
			}
		}
		return -1;
	}
};