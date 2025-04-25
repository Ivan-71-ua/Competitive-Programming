#include <bits/stdc++.h>


	class Solution {
	public:
		int numSquares(int n) {
			int k = sqrt(n);
			std::vector<int> dp(n + 1, n + 1);
			dp[0] = 0;
			for (int i = 1; i < n +1; i++)
			{
				for (int j = 1; j <= k; j++)
				{
					if(i - (j * j) > -1) {
						if(dp[i - (j * j)] > -1) {
							dp[i] = std::min(dp[i], dp[i - (j * j)] + 1);
						}
					} else {
						break;
					}
				}
				
			}
			return dp[n];
		}
	};

int main() {
	Solution ans;
	ans.numSquares(12);
}