#include <bits/stdc++.h>



class Solution {
public:
	int minChanges(int n, int k) {
		if((n ^ k) & k == 0) {
			return std::__popcount((n ^ k));
		}
		return -1;
	}
};