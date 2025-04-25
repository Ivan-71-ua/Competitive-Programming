#include <bits/stdc++.h>

class Solution {
private:
	void update(int ind, std::vector<int>& happiness) {
		for(int i=0; i<ind; i++) {
			if(happiness[i] != 0) happiness[i] -= 1;
		}
	}
public:
	long long maximumHappinessSum(std::vector<int>& happiness, int k) {
		std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
		std::sort(happiness.begin(), happiness.end(), std::greater<int>());
		long long sum = 0;
		for(int i = 0; i < k; i++) {
			happiness[i] = std::max(0, happiness[i] - i);
			sum += happiness[i];
		}
		return sum;
	}
};