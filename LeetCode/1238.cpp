#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> circularPermutation(int n, int start) {
		int size = (1 << n) - 1;
		std::vector<int> grey(size);
		for (int i = 0; i < size; i++) {
			grey[i] = i ^ (i >> 1);
		}
		
		for (int i = 0; i < size; i++) {
			grey[i] ^= start;
		}
		
		return grey;
	}
};