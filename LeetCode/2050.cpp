#include <bits/stdc++.h>


class Solution {
	std::vector<int> dp;
	int min_time(int v, int n, std::vector<std::vector<int>> &edges, std::vector<int>& time) {
		if(dp[v] != 0) {
			return dp[v];
		}
		int res = time[v - 1];
		for (auto next: edges[v])
		{
			res = std::max(res, time[v - 1] + min_time(next, n, edges, time));
		}
		dp[v] = res;
		return res;
	}
public:
	int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
		dp.resize(n + 1, 0);
		std::vector<std::vector<int>> edges(n + 1);
		for (auto edge: relations)
		{
			edges[edge[0]].push_back(edge[1]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			min_time(i, n, edges, time);
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};