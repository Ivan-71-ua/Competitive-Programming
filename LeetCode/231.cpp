#include <bits/stdc++.h>

class Solution {
public:
	bool isPowerOfTwo(int n) {
		long long tp = 1;
		while(tp <= n) {
			if(tp == n)
				return 1;
			tp = tp << 1;
		}
		return 0;
	}
};