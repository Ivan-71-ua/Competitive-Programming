#include <bits/stdc++.h>




class Solution {
	
public:
	char kthCharacter(long long k, std::vector<int>& operations) {
		int8_t cnt = 0;
		k--;
		for (int i = 0; k != 0; i++, k >>= 1) {
			cnt += ((k & 1) & operations[i]);
		}
		return 'a' + cnt % 26;
	}
};