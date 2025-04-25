#include <bits/stdc++.h>


class Solution {
public:
	bool isPerfectSquare(int n) {
		long long l = 1;
		long long r = n;
		while (l <= r)
		{
			long long mid = (l + r) / 2;
			if(mid * mid == n)
				return true;
			else if(mid * mid < n) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return false;
	}
};