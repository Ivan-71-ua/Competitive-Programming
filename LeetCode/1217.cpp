#include <bits/stdc++.h>


class Solution {
public:
	int minCostToMoveChips(std::vector<int>& position) {
		int even = 0, odd = 0;
		for (auto num: position)
		{
			if(num &1) {
				odd++;
			} else {
				even++;
			}
		}
		return std::min(odd, even);
	}
};