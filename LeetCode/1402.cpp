#include <bits/stdc++.h>


class Solution {
public:
	int maxSatisfaction(std::vector<int>& satisfaction) {
		std::stable_sort(satisfaction.begin(), satisfaction.end());
		if(satisfaction.back() <= 0)
			return 0;
		int res = 0;
		int sum = 0;
		for (int i = satisfaction.size() - 1; i > -1; i--)
		{
			sum += satisfaction[i];
			if(res < res + sum) {
				res += sum;
			} else {
				break;
			}
		}
		return res;
	}
};