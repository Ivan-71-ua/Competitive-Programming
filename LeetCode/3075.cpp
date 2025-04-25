#include <bits/stdc++.h>


class Solution {
public:
	long long maximumHappinessSum(std::vector<int>& happiness, int k) {
		std::stable_sort(happiness.begin(), happiness.end(), std::greater());
		long long res = 0;
		long long dis = 0;
		for (int i = 0; i < k; i++)
		{
			res += happiness[i] - dis > 0 ? happiness[i] - dis : 0;
			dis++;
		}
		return res;
	}
};