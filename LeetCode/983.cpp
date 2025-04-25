#include <bits/stdc++.h>

class Solution {
public:
   int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
		std::set<int> day(days.begin(), days.end());
		std::vector<int> dp(366);
		for (int i = 1; i < days[days.size() - 1] + 1; i++)
		{
			if(day.count(i)) {
				dp[i] = std::min({costs[0] + dp[i - 1], costs[1] + dp[std::max(0, i - 7)], costs[2] + dp[std::max(0, i -30)]});
			} else {
				dp[i] = dp[i - 1];
			}
		}
		return dp[days[days.size() - 1]];
	}
};

int main () {
	Solution ans;
	std::vector<int> ss{1, 4, 6, 7, 8, 20};
	std::vector<int> kk{7,2,15};
	ans.mincostTickets(ss, kk);
}