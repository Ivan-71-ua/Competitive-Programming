#include <bits/stdc++.h>

class Solution {
public:
	bool isPowerOfFour(int n) {
		long long tp = 1;
		while(tp <= n) {
			if(n == tp)
				return 1;
			tp = tp << 2;
		}
		return 0;
	}
};

