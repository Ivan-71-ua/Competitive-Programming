#include <bits/stdc++.h>

class Solution {
public:
	int hammingDistance(int x, int y) {
		std::bitset<32> res(x ^ y);
		return res.count();
	}
};