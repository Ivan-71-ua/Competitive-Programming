
#include <bits/stdc++.h>


class Solution {
	std::vector<std::vector<int>> res;
	std::vector<int> cur;
	void get_c(int id, int n, int k) {
		if(cur.size() == k) {
			res.push_back(cur);
			return;
		}
		for (int i = id; i <= n; i++)
		{
			cur.push_back(i);
			get_c(i + 1, n, k);
			cur.pop_back();
		}
	}

public:
	std::vector<std::vector<int>> combine(int n, int k) {
		get_c(1, n, k);
		return res;
	}
};