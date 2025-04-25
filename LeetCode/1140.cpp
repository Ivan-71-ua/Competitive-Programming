#include <bits/stdc++.h>



class Solution {
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
		for (int start = size - 1; start > -1; start--)
		{
			for (int m = 1; m <= size ; m++)
			{
				if(start + m * 2 >= size) {
					dp[start][m] = sumFrom[start];
				} else {
					for (int X = 1; X <= m * 2; X++)
					{
						dp[start][m] = std::max(dp[start][m], sumFrom[start] - dp[start + X][std::max(X, m)]);
					}
				}
			}
		}
		return dp[0][1];
	}
};