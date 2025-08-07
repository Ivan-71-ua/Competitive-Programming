
#include <bits/stdc++.h>

class Solution {
public:
	int maxCollectedFruits(std::vector<std::vector<int>>& fruits) {
		int res = 0, n = fruits.size();
		for (int i = 0; i < n; i++) {
			res += fruits[i][i];
		}

		for (int step = 0; step < 2; step++) {
			if(step == 1) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < i; j++) {
						std::swap(fruits[i][j], fruits[j][i]);
					}
				}
			}
			std::vector<int> prev(n, INT32_MIN);
			std::vector<int> cur(n, INT32_MIN);
			prev[n - 1] = fruits[0][n - 1];
			for (int i = 1; i < n - 1; i++) {
				for (int j = std::max(n - i - 1, i + 1); j < n; j++) {
					int best = prev[j];
					if(j > 0) {
						best = std::max(best, prev[j - 1]);
					}
					if(j + 1 < n) {
						best = std::max(best, prev[j + 1]);
					}
					cur[j] = fruits[i][j] + best;
				}
				std::swap(cur, prev);
			}
			res += prev[n - 1];
		}
		return res;
	}
};
