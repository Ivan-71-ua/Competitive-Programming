#include <bits/stdc++.h>



class Solution {
public:
	int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		std::vector<int> prev(m);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			std::vector<int> height(m);
			for (int j = 0; j < m; j++)
			{
				if(matrix[i][j]) {
					height[j] = matrix[i][j] + prev[j];
				}
			}
			prev = height;
			std::stable_sort(height.begin(), height.end(), std::greater());
			for (int i = 0; i < m && height[i] > 0; i++)
			{
				res = std::max(res, height[i] * (i + 1));
			}
		}
		return res;
	}
};