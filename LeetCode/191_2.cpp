#include <bits/stdc++.h>


class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while(n != 0) {
			if(n & 1) {
				res++;
			}
			n = n >> 1;
		}
		return res;
	}
};