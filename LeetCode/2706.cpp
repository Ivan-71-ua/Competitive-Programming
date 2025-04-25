#include <bits/stdc++.h>

class Solution {
public:
   int buyChoco(std::vector<int>& prices, int money) {
		int min = 100, min2 = 101;
		for (int i = 0; i < prices.size(); i++)
		{
			if(prices[i] < min) {
				min2 = min;
				min = prices[i];
			} else if(prices[i] < min2) {
				min2 = prices[i];
			}
		}
		if(money - (min + min2) < 0) {
			return money;
		} else {
			return money - (min + min2);
		}
	}
};