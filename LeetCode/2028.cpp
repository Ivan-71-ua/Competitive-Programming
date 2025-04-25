#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
		int m = rolls.size();
		int finals = mean * (n + m);
		long long sum_m = std::accumulate(rolls.begin(), rolls.end(), 0);
 		if((finals - sum_m + 5) / 6 > n || finals - sum_m < n) {
			return {};
		}
		int sum_n = finals - sum_m;
		int k = sum_n / n;
		std::vector<int> ans(n, k);
		for (int i = 0; i < sum_n % n; i++)
		{
			ans[i]++;
		}
		return ans;
	}
};

int main() {
	Solution anss;
	std::vector<int> ssd{4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
	anss.missingRolls(ssd, 4, 40);
}