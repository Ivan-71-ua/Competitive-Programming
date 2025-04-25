#include <bits/stdc++.h>


class Solution {
	long long Combinations(int start, int low, int finish, std::vector<int> &dp, int one, int zero) {
		if(start > finish)
			return 0;
		if(dp[start] != -1) {
			return dp[start];
		}
		dp[start] = start >= low ? 1 : 0;
		dp[start] += Combinations(start + one, low, finish, dp, one, zero) + Combinations(start + zero, low, finish, dp, one, zero);
		return dp[start] % (1000000000 + 7);
	}
public:
	int countGoodStrings(int low, int high, int zero, int one) {
		std::vector<int> dp(high + 1, -1);
		return Combinations(0, low,  high, dp, one, zero);
	}
};