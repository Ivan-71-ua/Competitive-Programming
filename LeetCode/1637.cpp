#include <bits/stdc++.h>

class Solution {
public:
   int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
		int ans = -1;
		std::sort(points.begin(), points.end());
		for (int i = 0; i < points.size() -1; i++)
		{
			if(points[i +1][0] - points[i][0] > ans) {
				ans = points[i + 1][0] - points[i][0];
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> points{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
	ans.maxWidthOfVerticalArea(points);
}