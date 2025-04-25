#include <bits/stdc++.h>




class Solution {
	void EraseMidleNodes(int l, int r, std::set<int> &dist) {
		auto start = dist.lower_bound(l);
		auto finish = dist.upper_bound(r);
		dist.erase(start, finish);
	}
public:
	std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
		std::set<int> dist;
		for (int i = 0; i < n; i++)
		{
			dist.insert(i);
		}
		std::vector<int> ans(queries.size());
		for (int i = 0; i < queries.size(); i++)
		{
			int x = queries[i][0];
			int y = queries[i][1];
			EraseMidleNodes(x + 1, y - 1, dist);
			ans[i] = dist.size() - 1;
		}
		return ans;
	}
};