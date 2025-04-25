#include <bits/stdc++.h>

class Solution {
public:
	double new21Game(int n, int k, int maxPts) {
		if(k == 0 || n >= k + maxPts) {
			return 1;
		}
		std::vector<double> dp(n + 1, 0.0);
		dp[0] = 1;
		double SumCurr = dp[0];
		for (int i = 1; i <= n; i++)
		{
			dp[i] = SumCurr / (double)maxPts;
			if(i < k) {
				SumCurr += dp[i];
			}
			if(i - maxPts >= 0) {
				SumCurr -= dp[i - maxPts];
			}
		}
		double ans = 0;
		for (int i = k; i <= n; i++)
		{
			ans += dp[i];
		}
		return ans;
	}
};