#include <bits/stdc++.h>

class Solution {
	const long long MOD = 1000000007LL;
	long long powMod(long long a, long long b) {
		a %= MOD;
		long long res = 1;                
		while (b) {
			if (b & 1) res = (res * a) % MOD;
			a = (a * a) % MOD;
			b >>= 1;
		}
		return res;
	} 
public:
	std::vector<int> productQueries(int n, std::vector<std::vector<int>> &queries)
	{
		int s_n = queries.size();
		std::vector<int> powers;
		for (int i = 0; i < 32; i++) {
			if((1 << i) & n) {
				powers.push_back(i);
			}
		}
		int m = powers.size();
		std::vector<int> pref(m);
		pref[0] = powers[0];
		for (int i = 1; i < m; i++) {
			pref[i] = pref[i - 1] + powers[i];
		}
		std::vector<int> ans(s_n);
		for (int i = 0; i < s_n; i++) {
			int l = queries[i][0], r = queries[i][1];
			if(l > 0) {
				ans[i] = powMod(2, pref[r] - pref[l - 1]);
			} else {
				ans[i] = powMod(2, pref[r]);
			}
		}
		return ans;
	}
};