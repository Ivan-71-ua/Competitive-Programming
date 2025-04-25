#include <bits/stdc++.h>

void dfs(int v, int parent, std::vector<std::vector<int>> &list, std::vector<std::vector<int>> &dp) {
	for(auto child: list[v]) {
		if(child != parent) {
			dfs(child, v, list, dp);
			int val = dp[child][0] + (child % 2 == 0 ? 2 : 1);
			if(val > dp[v][0]) {
				dp[v][1] = dp[v][0];
				dp[v][0] = val;
			} else if(val > dp[v][1]) {
				dp[v][1] = val;
			}
		}
	}
}

void MaxTime(int v, int parent, int incoming, std::vector<int> &ans, std::vector<std::vector<int>> &list, std::vector<std::vector<int>> &dp) {
	ans[v] = std::max(dp[v][0], incoming);
	for (auto next: list[v])
	{
		int pr = v % 2 == 0 ? 2 : 1;	
		if(next != parent) {
			int cur = dp[next][0] + (next % 2 == 0 ? 2 : 1);
			int x = -1;
			if(cur == dp[v][0]) {
				x = dp[v][1];
			} else {
				x = dp[v][0];
			}
			MaxTime(next, v, std::max(pr + incoming, pr + x), ans, list, dp);
		}
	}
	
}



class Solution {
public:
	std::vector<int> timeTaken(std::vector<std::vector<int>>& edges) {
		int n = edges.size() + 1;
		std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
		std::vector<std::vector<int>> list(n);
		std::vector<int> ans(n);
		for(auto ver: edges) {
			list[ver[0]].push_back(ver[1]);
			list[ver[1]].push_back(ver[0]);
		}
		dfs(0, -1, list, dp);
		MaxTime(0, -1, 0, ans, list, dp);
		return ans;
	}
};