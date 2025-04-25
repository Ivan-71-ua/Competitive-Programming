#include <bits/stdc++.h>

class Solution {
public:
	int bitwiseComplement(int n) {
		if(n == 0)
			return 1;
		if(!(n & (n - 1)))
			return n - 1;
		int k = 1;
		while(k < n) {
			k <<= 1;
		}
		k--;
		return k ^ n;
	}
};