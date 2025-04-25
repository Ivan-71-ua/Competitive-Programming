#include <bits/stdc++.h>


class Solution {
public:
	long long minEnd(int n, int x) {
		long long res = x;
		long long x_i = 1;
		long long n_i = 1;
		while(n_i <= n - 1) {
			if((x & x_i) == 0) {
				if(((n - 1) & n_i)) {
					res |= x_i;
				}
				n_i <<= 1;
			}
			x_i <<= 1;
		}
		return res;
	}
};