#include <bits/stdc++.h>

class Solution {
public:
   int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
		std::vector<int> minCost(days.size());
		int i1 = -1;
		int i7 = -1;
		int i30 = -1;
		for (int i = 0; i < days.size(); i++)
		{
			while(days[i1 + 1] <= days[i] -1) {
				i1++;
			}
			while(days[i7 + 1] <= days[i] -7) {
				i7++;
			}
			while(days[i30 + 1] <= days[i] - 30) {
				i30++;
			}
			minCost[i] = std::min({costs[0] + (i1 >= 0 ? minCost[i1] : 0),
											costs[1] + (i7 >= 0 ? minCost[i7] : 0),
											costs[2] + (i30 >= 0 ? minCost[i30] : 0)});
		}
		return minCost.back();
	}
};

int main () {
	Solution ans;
	std::vector<int> ss{1, 4, 6, 7, 8, 20};
	std::vector<int> kk{7,2,15};
	ans.mincostTickets(ss, kk);
}