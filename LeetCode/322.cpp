#include <bits/stdc++.h>
// NOT WORK(GREEDY)
/*
class Solution {
public:
   int coinChange(std::vector<int>& coins, int amount) {
		
		std::sort(coins.begin(), coins.end());
		//if (coins[0] > amount && amount != 0)
			//return -1;
		int res = INT32_MAX;
		for (int i = 0; i < coins.size(); i++)
		{
			int tp = amount % coins[i];
			if(tp == 0) {
				res = std::min(res, amount / coins[i]);
			} else {
				int ans = amount / coins[i];
				int k = i;
				while(true) {
					while(tp < coins[k] && k - 1 >= 0) {
					k--;
					} if(tp < coins[k]) break;
					int ost = tp % coins[k];
					if(ost == 0) {
						res = std::min(res, ans + tp / coins[k]);
						break;
					} else {
						ans += tp / coins[k];
						tp %= coins[k];
					}
				}
				
			}
		}
		if(res == INT32_MAX) return -1;
		return res;
	}
};
*/
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> may_way(amount + 1, amount + 1);
        may_way[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i) {
                    may_way[i] = std::min(may_way[i], may_way[i - coins[j]] + 1);
                }
            }
        }
        if(may_way[amount] == amount + 1)
            return -1;
        return may_way[amount];
    }
};

int main() {
	Solution ans;
	std::vector<int> ss{1,2,5};
	ans.coinChange(ss, 11);
}
