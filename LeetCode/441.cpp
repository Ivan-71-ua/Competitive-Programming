#include <bits/stdc++.h>


class Solution {
public:
	int arrangeCoins(int n) {
		int res = 0;
		int j = 1;
		while(n - j > -1) {
			res++;
			n -= j;
			j++;
		}
		return res;
	}
};