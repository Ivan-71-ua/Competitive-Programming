#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> finalPrices(std::vector<int>& prices) {
		std::stack<int> nums;
		int n = prices.size();
		std::vector<int> res(n);
		for (int i = n - 1; i > -1; i--)
		{
			while(!nums.empty() && nums.top() > prices[i]) {
				nums.pop();
			}
			if(nums.empty()) {
				res[i] = prices[i];
			} else {
				res[i] = prices[i] - nums.top();
			}
			nums.push(prices[i]);
		}
		return res;
	}
};