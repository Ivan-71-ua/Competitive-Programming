#include <bits/stdc++.h>


class Solution {
public:
	int maxIceCream(std::vector<int>& costs, int coins) {
		std::vector<int> candies(100000 + 7);
		int ans = 0;
		for (auto now: costs)
		{
			candies[now]++;
		}
		for (int i = 1; i < 100000 + 3; i++)
		{
			if(!candies[i]) continue;
			ans += std::min(candies[i], coins / i);
			if(candies[i] > coins / i) break;
			coins -= i * candies[i];
		}
		return ans;
	}
};