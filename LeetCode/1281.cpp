#include <bits/stdc++.h>




class Solution {
public:
	int subtractProductAndSum(int n) {
		int d = 1;
		int s = 0;
		while(n != 0) {
			int k = n % 10;
			n /= 10;
			d *= k;
			s += k;
		}
		return d - s;
	}
};