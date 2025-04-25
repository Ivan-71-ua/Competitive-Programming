#include <bits/stdc++.h>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		std::vector<int> bestSum(prices.size());
		int ans = 0;
		for (int lastSell = 1; lastSell < prices.size(); lastSell++)
		{
			for (int lastBuy = 0; lastBuy < lastSell; lastBuy++)
			{
				bestSum[lastSell] = std::max(bestSum[lastSell], prices[lastSell] - prices[lastBuy]);
				for (int prefSell = 1; prefSell < lastBuy -1; prefSell++)
				{
					bestSum[lastSell] = std::max(bestSum[lastSell], prices[lastSell] - prices[lastBuy] + bestSum[prefSell]);
				}
			}
			ans = std::max(ans, bestSum[lastSell]);
		}
		return ans;
	}
};