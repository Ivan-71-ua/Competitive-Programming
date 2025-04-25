#include <bits/stdc++.h>


class Solution {
public:
   bool isPowerOfThree(int n) {
      if(n == 1)
			return 1;
		if(n <= 0)
			return 0;
		long long res = 3;
		while(res <= n) {
			if(res == n) {
				return 1;
			}
			res *= 3;
		}
		return 0;
	}
};