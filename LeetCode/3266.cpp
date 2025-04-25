#include <bits/stdc++.h>



class Solution {
	const int MOD = 1e9 + 7;
	int modpow(long long base, int exp) {
		long long res = 1;
		while(exp) {
			if(exp & 1) {
				res *= base;
				res %= MOD;
			}
			base *=  base;
			base %= MOD;
			exp >>= 1;
		}
		return res;
	}
public:
	std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
		if(multiplier == 1)
			return nums;
		int n = nums.size();
		int maxs = *std::max_element(nums.cbegin(), nums.cend());
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
		for (int i = 0; i < n; i++)
		{
			q.push({nums[i], i});
		}
		while(k && 1LL * multiplier * q.top().first <= maxs) {
			k--;
			q.push({(1LL * multiplier * q.top().first) % MOD, q.top().second});
			q.pop();
		}
		int pmod = modpow(multiplier, k / n);
		while (!q.empty())
		{
			auto [val, idx] = q.top();
			q.pop();
			if(k % n != 0) {
				k--;
				nums[idx] = ((1LL * multiplier * pmod) % MOD * val) % MOD;
			} else {
				nums[idx] = (1LL * pmod  * val) % MOD;
			}
		}
		return nums;
	}
};