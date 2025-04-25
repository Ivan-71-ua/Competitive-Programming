#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second) {
		if (first.size() > second.size()) std::swap(first, second);
		std::vector<std::vector<int>> res;

		for (auto& pr : first)
		{
			int a, b;
			a = pr[0], b = pr[1];
			for (auto& cur : second)
			{
					int c = cur[0], d = cur[1];
					if (b < c || d < a) continue;
					res.push_back({ std::max(a, c), std::min(d, b) });
			}

		}

		return res;
	}
};