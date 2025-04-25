#include <bits/stdc++.h>

class Solution {
public:
	int maxPointsInsideSquare(std::vector<std::vector<int>>& points, std::string s) {
		int count = 0, second_min = INT32_MAX;
		std::unordered_map<char, int> min_len;
		for (int i = 0; i < points.size(); i++)
		{
			int len = std::max(abs(points[i][0]), abs(points[i][1]));
			char cur = s[i];
			if(min_len.count(cur)) {
				if(len < min_len[cur]) {
					second_min = std::min(second_min, min_len[cur]);
					min_len[cur] = len;
				} else {
					second_min = std::min(second_min, len);
				}
			} else {
				min_len[cur] = len;	
			}
		}
		for (auto now: min_len)
		{
			if(now.second < second_min) {
				count++;
			}
		}
		return count;
	}
};