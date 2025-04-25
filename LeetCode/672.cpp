#include <bits/stdc++.h>

class Solution {
public:
	int countPrimeSetBits(int left, int right) {
		int res = 0;
		for (int i = left; i <= right; i++)
		{
			std::bitset<32> num(i);
			int k = num.count();
			bool is = true;
			if(k <= 1)
				is = false;
			else {
				for (int j = 2; j * j <= k ; j++)
				{
					if(k % j == 0) {
						is = false;
						break;
					}
				}
			}
			if(is)
				res++;
		}
		return res;
	}
};