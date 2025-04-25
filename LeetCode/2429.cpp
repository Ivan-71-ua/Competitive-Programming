#include <bits/stdc++.h>


class Solution {
	int ones(int n) {
		int res = 0;
		while(n) {
			res += n & 1;
			n <<= 1;
		}
		return res;
	}
public:
	int minimizeXor(int num1, int num2) {
		int k1 = ones(num2), k2 = ones(num1);
		if(k1 == k2) {
			return num1;
		}
		int cur = std::max(k1, k2);
		int res = 0;
		int idx = 1 << 31;
		while(idx != 0 && cur != 0) {
			if(idx & num1) {
				cur--;
				res ^= idx;
			}
			idx >>= 1;
		}
		idx = 1;
		while(k2 > k1) {
			if(!(idx & num1)) {
				k2--;
				res ^= idx;
			}
			idx <<= 1;
		}
		return res;
	}
};
