#include <bits/stdc++.h>

class Solution {
public:
	double findMaxAverage(std::vector<int>& nums, int k) {
		double sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += nums[i];
		}
		double res = sum;
		for (int i = k, j = 0; i < nums.size(); i++, j++)
		{
			sum -= nums[j];
			sum += nums[i];
			res = std::max(res, sum);
		}
		return res / k;
	}
};