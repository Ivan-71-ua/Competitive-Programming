#include <bits/stdc++.h>

class Solution {
public:
   int maxProfit(std::vector<int>& prices) {
		int maxPrifit = 0;
		for (int i = 0; i < prices.size() -1; i++)
		{
			if(prices[i] < prices[i +1])
				maxPrifit += prices[i +1] - prices[i];
		}
		return maxPrifit;
	}
};

int main() {
	Solution ans;
	std::vector<int> an{7, 1, 5, 3, 6, 4};
	ans.maxProfit(an);
}