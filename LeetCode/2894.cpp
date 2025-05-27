
#include <bits/stdc++.h>


class Solution {
public:
	int differenceOfSums(int n, int m) {
		int sum2 = 0, mult = 0;
		while(mult + m <= n) {
			mult += m;
			sum2 += mult;
		}
		int sum1 = (n * (n + 1)) / 2 - sum2;
		return sum1 - sum2;
	}
};