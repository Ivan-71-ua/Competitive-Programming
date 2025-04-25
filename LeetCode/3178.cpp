#include <bits/stdc++.h>

class Solution {
public:
	int numberOfChild(int n, int k) {
		n--;
		int round = k / n;
		int step = k % n;
		if(round & 1) {
			return n - step;
		}
		return step;
	}
};