#include <bits/stdc++.h>


class Solution {
public:
	long long putMarbles(std::vector<int>& weights, int k) {
		std::vector<long long> cuts;
		for (int i = 1; i < weights.size(); i++)
		{
			cuts.push_back(weights[i - 1] + weights[i]);
		}
		std::stable_sort(cuts.begin(), cuts.end());
		long long maxs = 0, mins = 0;
		int i = 0, j = cuts.size()-1;
		while(k != 1) {
			maxs += cuts[j--];
			mins += cuts[i++];
			k--;
		}
		
		return maxs - mins;
	}
};