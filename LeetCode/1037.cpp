#include <bits/stdc++.h>


class Solution {
public:
	bool isBoomerang(std::vector<std::vector<int>>& points) {
		int x1 = points[0][0];
		int y1 = points[0][1];
		int denominator1 = points[1][0] - points[0][0];
		int denominator2 = points[1][1] - points[0][1];
		if((points[2][0] - x1) * denominator2 != (points[2][1] - y1) * denominator1) {
			return true;
		}
		return false;
	}
};