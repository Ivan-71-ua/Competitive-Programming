#include <bits/stdc++.h>





class Solution {
public:
	int minOperations(std::vector<std::vector<int>>& grid, int x) {
		int n = grid.size(), m = grid[0].size();
		long long sum = 0;
		std::vector<int> a(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i * m + j] = grid[i][j];
				sum += grid[i][j];
			}
		}
		std::sort(a.begin(), a.end());
		for (int i = 1; i < n * m; i++) {
			if((a[i] - a[i - 1]) % x != 0)
				return -1;
		}
		int need = -1;
		need = a[n * m / 2];
		int res = 0;
		for (int i = 0; i < n * m; i++) {
			res += abs(a[i] - need) / x;
		}
		return res;
	}
};