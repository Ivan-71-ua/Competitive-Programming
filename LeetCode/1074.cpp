#include <bits/stdc++.h>

class Solution {
public:
	int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		std::vector<std::vector<int>> pref_sum(n + 1, std::vector<int>(m + 1));
		for (int i = 0; i < n; i++)
		{
			std::vector<int> cur_row(m + 1);
			for (int j = 0; j < m; j++)
			{
				cur_row[j + 1] = cur_row[j] + matrix[i][j];
				pref_sum[i + 1][j + 1] = pref_sum[i][j + 1] + cur_row[j +1];
			}
		}
		int ans = 0;
		for (int r1 = 1; r1 <= n; r1++)
		{
			for (int r2 = r1; r2 <= n; r2++)
			{
				std::unordered_map<int, int> cur_pref;
				cur_pref[0] = 1;
				for (int c = 1; c <= m; c++)
				{
					int cur_sum = pref_sum[r2][c] - pref_sum[r1 - 1][c];
					int diff = cur_sum - target;
					ans += cur_pref[diff];
					cur_pref[cur_sum]++;
				}
			}
		}
		return ans;
	}
};