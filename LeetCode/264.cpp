#include <bits/stdc++.h>



class Solution {
public:
	int nthUglyNumber(int n) {
		int MAX_L = 1960;
		std::vector<long long> dp(MAX_L);
		dp[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i < MAX_L; i++)
		{
			dp[i] = std::min({dp[i2] * 2, dp[i3] * 3, dp[i5] * 5});
			int ugly = dp[i];
			if(ugly == dp[i2] * 2)
				i2++;
			if(ugly == dp[i3] * 3)
				i3++;
			if(ugly == dp[i5] * 5)
				i5++;
		}
		return dp[n - 1];
	}
};