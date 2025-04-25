#include <bits/stdc++.h>

class Solution {
	int next(int a) {
		int res = 0;
		while (a > 0)
		{
			int tmp = a % 10;
			a /= 10;
			res += tmp * tmp;
		}
		return res;
	}
public:
	bool isHappy(int n) {
		int slow = n;
		int fast = n;
		while(true) {
			slow = next(slow);
			fast = next(next(fast));
			if(fast == 1) {
				return true;
			}
			if(fast == slow)
				return false;
		}
	}
};