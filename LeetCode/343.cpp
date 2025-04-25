#include <bits/stdc++.h>


class Solution {
public:
   int integerBreak(int n) {
		if(n == 2) {
			return 1;
		} if(n == 3) {
			return 2;
		}
		int tp = n % 3;
		if(tp == 0) {
			return pow(3, n / 3);
		} else if(tp == 1) {
			return 4 * pow(3, (n - 4) / 3); 
		} else {
			return 2 * pow(3, (n - 2) / 3);
		}
	}
};