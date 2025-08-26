#include <bits/stdc++.h>



class Solution {
public:
	int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
		int res = -1, d = -1;
		for (auto t: dimensions) {
			int a = t[0], b = t[1];
			if(a * a + b * b > d) {
				res = a * b;
				d = a * a + b * b;
			} else if(a * a + b * b == d) {
				res = std::max(a * b, res);
			}
		}
		return res;
	}
};