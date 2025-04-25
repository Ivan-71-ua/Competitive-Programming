#include <bits/stdc++.h>


class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		std::bitset<32> bitwise(n);
		std::bitset<32> res;
		for (int i = 0; i < 32; i++)
		{
			res[i] = bitwise[32 - i -1];
		}
		return res.to_ullong();
	}
};