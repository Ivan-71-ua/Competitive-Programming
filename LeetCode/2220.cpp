#include <bits/stdc++.h>


class Solution {
public:
	int minBitFlips(int start, int goal) {
		std::bitset<32> a(start);
		std::bitset<32> b(goal);
		a = a ^ b;
		return a.count();
	}
};