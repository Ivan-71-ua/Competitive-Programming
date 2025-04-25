#include <bits/stdc++.h>


class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		std::vector<int> bestSum(prices.size()); // bestSum[i] - sum if last seel on day i
		std::vector<int> bestSumPrefMax(prices.size());// bestSum[i] = max(0, bestSum[0]... bestSum[i])
		std::vector<int> bestDiff(prices.size());//bestDiff[i] = max(-prices[j <= i] + bestPrefMax[k < j -1])
		for (int day = 0; day < prices.size(); day++)
		{
			bestDiff[day] = -prices[day] + (day >= 2 ? bestSumPrefMax[day - 2] : 0);
			if(day  -1 >=0) {
				bestDiff[day] = std::max(bestDiff[day], bestDiff[day - 1]);
				bestSum[day] = prices[day] + bestDiff[day - 1];
				bestSumPrefMax[day] = std::max(bestSumPrefMax[day - 1], bestSum[day]);
			}
		}
		return bestSumPrefMax.back();
	}
};