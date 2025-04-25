#include <bits/stdc++.h>

class Solution {
public:
	int hammingDistance(int x, int y) {
		return std::__popcount(x ^ y);
	}
};