#include <bits/stdc++.h>


class Solution {
public:
	int maxTotalFruits(std::vector<std:: vector<int>>& fruits, int startPos, int k) {
		int res = 0, sum = 0, l = 0;
		for (int r = 0; r < fruits.size(); r++) {
			sum += fruits[r][1];
			while(l <= r && (fruits[r][0] - fruits[l][0]) + std::min(abs(startPos - fruits[l][0]), abs(startPos - fruits[r][0])) > k) {
				sum -= fruits[l++][1];
			}
			res = std::max(res, sum);
		}
		return res;
	}
};