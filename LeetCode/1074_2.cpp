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
					for (int c1 = 1; c1 <= m; c1++)
					{
						for (int c2 = c1; c2 <= m; c2++)
						{
							int cur_sum = pref_sum[r2][c2] - pref_sum[r1 - 1][c2] - pref_sum[r2][c1 - 1] + pref_sum[r1 - 1][c1 - 1];
							if(cur_sum == target)
								ans++;
						}
						
					}
				}
			}
			return ans;
		}
	};