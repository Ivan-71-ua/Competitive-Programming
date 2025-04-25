#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> countPoints(std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& queries) {
		std::vector<int> ans;
		for (int i = 0; i < queries.size(); i++)
		{
			int count = 0;
			int r = queries[i][2];
			int a = queries[i][0];
			int b = queries[i][1];
			for (int j = 0; j < points.size(); j++)
			{
				int x = points[j][0];
				int y = points[j][1];
				if((x - a) * (x - a) + (y - b) * (y - b) <= r * r) {
					count++;
				}
			}
			ans.push_back(count);
		}
		return ans;
	}
};