#include <bits/stdc++.h>


class Solution {
public:
	int findComplement(int num) {
		int left = 0;
		int right = 31;
		while(right > left +1) {
			int mid = (right + left) >> 1;
			if((1 << mid)  > num) {
				right = mid;
			} else {
				left = mid;
			}
		}
		int mask = (1 << left) + ((1 << left) - 1);
		return num ^ mask;
	}
};