#include <bits/stdc++.h>


int guess(int num);


class Solution {
public:
	int guessNumber(int n) {
		long long l = 1;
		long long r = n;
		while(l <= r) {
			long long mid = (l + r) / 2;
			if(guess(mid) == 0)
				return mid;
			else if(guess(mid) ==  -1) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return 0;
	}
};