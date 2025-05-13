#include <bits/stdc++.h>



class Solution {
	const int MOD = 1e9 + 7;
public:
	int lengthAfterTransformations(std::string s, int t) {
		std::vector<long long> cnt(26, 0);
		for(char c : s) {
			cnt[c - 'a']++;
		}
		for (int i = 0; i < t; i++) {
			std::vector<long long> new_cnt(26, 0);
			new_cnt[0] = cnt[25];
			new_cnt[1] = (cnt[0] + cnt[25]) % MOD;
			for (int j = 2; j < 26; j++) {
				new_cnt[j] = cnt[j - 1];
			}
			cnt = std::move(new_cnt);
		}
		long long res = 0;
		for (int i = 0; i < 26; i++) {
			res = (res + cnt[i]) % MOD;
		}
		return res;
	}
};