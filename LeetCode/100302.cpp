#include <bits/stdc++.h>


class Solution {
	bool check_incide(std::vector<std::vector<int>>& points, int id, int radius) {
		return points[id][0] <= radius && points[id][1] <= radius;
	}
public:
	int maxPointsInsideSquare(std::vector<std::vector<int>>& points, std::string s) {
		for (int i = 0; i < points.size(); i++)
		{
			points[i][0] = abs(points[i][0]);
			points[i][1] = abs(points[i][1]);
		}
		int l = 0, r = 1000000000, radious = 0;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			std::unordered_map<char, int> used;
			bool repid = false;
			for (int i = 0; i < points.size(); i++)
			{
				if(check_incide(points, i, mid)) {
					used[s[i]]++;
				}
			}
			for (auto &&now : used)
			{
				if(now.second > 1) {
					repid = true;
					break;
				}
			}
			if(repid) {
				r = mid - 1;
			} else {
				radious = mid;
				l = mid + 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < points.size(); i++)
		{
			if(check_incide(points, i, radious)) {
				ans++;
			}
		}
		return ans;
	}
};

