#include <bits/stdc++.h>


class Solution {
	std::vector<int> res;
	void dfs(int cur, int n) {
		if(cur > n) {
			return;
		}
		res.push_back(cur);
		for (int i = 0; i < 10; i++)
		{
			dfs(cur * 10 + i, n);
		}
	}
public:
	std::vector<int> lexicalOrder(int n) {
		for (int i = 1; i < 10; i++)
		{
			dfs(i, n);
		}
		return res;
	}
};