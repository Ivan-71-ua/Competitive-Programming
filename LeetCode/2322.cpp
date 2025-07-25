#include <bits/stdc++.h>


class Solution {
	void dfs(int node, int parent, std::vector<std::vector<int>> &djs, std::vector<int> &dp, std::vector<int> &nums, std::vector<std::vector<int>> &time, int &t) {
		time[node][0] = t++;
      dp[node] ^= nums[node];
		for (int i = 0; i < djs[node].size(); i++) {
			int next = djs[node][i];
			if(next == parent) {
				continue;
			}
			dfs(next, node, djs, dp, nums, time, t);
			dp[node] ^= dp[next];
		}
		time[node][1] = t++;
	}
	int maxs(int a, int b, int c) {
		return std::max({a, b, c}) - std::min({a, b, c});
	}

public:
	int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
		int res = INT32_MAX;
		int n = nums.size(), m = edges.size(), t = 0;
		std::vector<int> dp(n, 0);
		std::vector<std::vector<int>> adj(n);
		std::vector<std::vector<int>> time(n, std::vector<int> (2, 0));
		for (int i = 0; i < m; i++) {
			int a = edges[i][0], b = edges[i][1];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0, -1, adj, dp, nums, time, t);
		int total = dp[0];
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int a, b, c;
				if(time[i][0] >= time[j][0] && time[i][1] <= time[j][1]) {
					a = dp[i];
					b = dp[i] ^ dp[j];
					c = total ^ dp[j];
				} else if(time[i][0] <= time[j][0] && time[i][1] >= time[j][1]) {
					a = dp[j];
					b = dp[i] ^ dp[j];
					c = total ^ dp[i];
				} else {
					a = dp[i];
					b = dp[j];
					c = total ^ dp[i] ^ dp[j];
				}
				res = std::min(res, maxs(a, b, c));
			}
		}
		return res;
	}
};