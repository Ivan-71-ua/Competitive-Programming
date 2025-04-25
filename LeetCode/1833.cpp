#include <bits/stdc++.h>


class Solution {
public:
	int maxIceCream(std::vector<int>& costs, int coins) {
		std::stable_sort(costs.begin(), costs.end());
		int ans = 0;
		for (int i = 0; i < costs.size(); i++)
		{
			if(coins >= costs[i]) {
				coins -= costs[i];
				ans++;
			} else {
				break;
			}
		}
		return ans;
	}
};