#include <bits/stdc++.h>

class Solution {
	
public:
	int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
		std::vector<int> dp(k);
		dp[0] = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			int cur_max = 0;
			int max_at_i = 0;
			for (int j = i; j > i - k; j--)
			{
				if(j < 0) break;
				cur_max = std::max(cur_max, arr[i]);
				int window_size = i - j + 1;
				int cur_sum = window_size * cur_max;
				int sub_sum = j > 0 ? dp[(j - 1) % k] : dp.back();
				max_at_i = std::max(max_at_i, cur_sum + sub_sum);
			}
			dp[i % k] = max_at_i;
		}
		return dp[(arr.size() - 1) % k];
	}
};
