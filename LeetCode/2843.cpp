
#include <bits/stdc++.h>




class Solution {
public:
	int countSymmetricIntegers(int low, int high) {
		int cnt = 0;
		for (int i = low; i <= high; i++) {
			if(i > 10 && i < 100) {
				cnt += i % 11 == 0 ? 1 : 0;
			} else if(i > 999 && i < 10000) {
				int first = i / 100;
				int second = i % 100;
				if(first / 10 + first % 10 == second / 10 + second % 10) 
					cnt++;
			}
		}
		return cnt;
	}
};