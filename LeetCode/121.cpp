#include <bits/stdc++.h>

class Solution {
public:
   int maxProfit(std::vector<int>& prices) {
		int min_start = prices[0];
		int max_prise = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			max_prise = std::max(prices[i] - min_start, max_prise);
			min_start = std::min(min_start, prices[i]);
		}
		return max_prise;
	}
};