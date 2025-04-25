#include <bits/stdc++.h>

class Solution {
public:
	int hammingWeight(uint32_t n) {
		std::bitset<32> bits(n);
		return bits.count();
	}
};