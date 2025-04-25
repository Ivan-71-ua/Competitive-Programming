#include <bits/stdc++.h>




class Solution {
	int cnt = 0;
	long long dfs(int v, int p, std::vector<std::vector<int>> &graf, std::vector<int>& values, int k) {
		long long cur = values[v];
		for (auto &&next : graf[v])
		{
			if(p != next) {
				cur += dfs(next, v, graf, values, k);
			}
		}
		if(cur % k == 0) {
			cnt++;
			cur = 0;
		}
		return cur;
	}
public:
	int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
		std::vector<std::vector<int>> graf(n);
		std::vector<int> in(n);
		for(auto &k : edges) {
			int a = k[0], b = k[1];
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		dfs(0, -1, graf, values, k);
		return cnt;
	}
};