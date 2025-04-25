#include <bits/stdc++.h>

class Solution {
public:
   int minCostClimbingStairs(std::vector<int>& cost) {
		cost.insert(cost.begin(), 0);
		cost.push_back(0);
		std::vector<int> prise (cost.size());
		prise[0] = cost[0];
		prise[1] = cost[0] + cost[1];
		for (int i = 2; i < cost.size(); i++)
		{
			prise[i] = std::min(prise[i - 1], prise[i - 2]) + cost[i];
		}
		return prise[cost.size() - 1];
	}
};

int main() {
	Solution an;
	std::vector<int> h{10,15,20};
	an.minCostClimbingStairs(h);
}