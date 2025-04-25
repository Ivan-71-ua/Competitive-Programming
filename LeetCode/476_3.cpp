#include <bits/stdc++.h>


class Solution {
public:
	int findComplement(int num) {
		int mask = 1;
		int ans = 0;
		while(num > 0)  {
			if((num & mask) == 0) {
				ans |= mask;
			} else {
				num ^= mask;
			}
			mask <<= 1;
		}
		return ans;
	}
};