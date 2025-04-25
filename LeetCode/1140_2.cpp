#include <bits/stdc++.h>



class Solution {
	int get_max_score(int start, int m, std::vector<std::vector<int>> &dp, std::vector<int> &sumFrom) {
		int size = dp.size();
		if(start + m * 2 >= size) {
			return sumFrom[start];
		}
		int &val = dp[start][m];
		if(val == 0) {
			
			for (int x = 1; x <= m * 2; x++)
			{
				val = std::max(val, sumFrom[start] - get_max_score(start + x, std::max(x, m), dp, sumFrom));	
			}
		}
		return dp[start][m];
	}
public:
	int stoneGameII(std::vector<int>& piles) {
		int size = piles.size();
		std::vector<int> sumFrom(size);
		sumFrom.back() = piles.back();
		for (int i = size - 2; i > -1; i--)
		{
			sumFrom[i] = piles[i] + sumFrom[i + 1];
		}
		std::vector<std::vector<int>> dp(size, std::vector<int>(size + 1, 0));
		return get_max_score(0, 1, dp, sumFrom);
	}
};