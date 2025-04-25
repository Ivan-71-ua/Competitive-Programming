#include <bits/stdc++.h>


class Solution {
	void dfs(std::vector<std::vector<int>> &list, std::vector<int> &subtree, std::vector<int> &height, int node, int parent) {
		subtree[node]++;
		for (auto &&next : list[node])
		{
			if(next != parent) {
				height[next] = 1 + height[node];
				dfs(list, subtree, height, next, node);
				subtree[node] += subtree[next];
			}
		}
	}
	void get_dist(std::vector<std::vector<int>> &list, std::vector<int> &subtree, std::vector<int> &dp, int n, int node, int parent) {
		for (auto &&next : list[node])
		{
			if(next != parent) {
				dp[next] = dp[node] - subtree[next] + (n - subtree[next]);
				get_dist(list, subtree, dp, n, next, node);
			}
		}
	}
public:
	std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
		std::vector<std::vector<int>> list(n);
		std::vector<bool> used(n);

		for (auto &ed: edges)
		{
			list[ed[0]].push_back(ed[1]);
			list[ed[1]].push_back(ed[0]);
		}
		std::vector<int> subtree(n), height(n), dp(n);
		dfs(list, subtree, height, 0, -1);
		for (int i = 0; i < n; i++)
		{
			dp[0] += height[i];
		}
		get_dist(list, subtree, dp, n, 0, -1);
		return dp;
	}
};