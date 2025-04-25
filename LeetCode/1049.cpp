#include <bits/stdc++.h>


class Solution {
	int rec_bag(int i, int total, std::vector<std::vector<int>> &cash, int sum, int target, std::vector<int>& stones){
		if(total >= target || i == cash.size() - 1)
			return abs(total - (sum - total));
		if(cash[i][total] != -1) {
			return cash[i][total];
		}
		cash[i][total] = std::min(rec_bag(i + 1, total, cash, sum, target, stones),rec_bag(i +1, total + stones[i], cash, sum, target, stones));
		return cash[i][total];
	}
public:
	int lastStoneWeightII(std::vector<int>& stones) {
		int sum = 0;
		for (int i = 0; i < stones.size(); i++)
		{
			sum += stones[i];
		}
		int target = (sum + 1) / 2;
		std::vector<std::vector<int>> cash(stones.size() + 1, std::vector<int>(sum + 1, -1));
		return rec_bag(0, 0, cash, sum, target, stones);
	}
};