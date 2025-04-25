#include <bits/stdc++.h>




class Solution {
	int get(int n) {
		int sum = 0;
		while(n) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
public:
	int countLargestGroup(int n) {
		std::vector<int> sums(37, 0);
		int mxs = 0;
		for (int i = 1; i < n + 1; i++) {
			int s = get(i);
			sums[s]++;
			mxs = std::max(mxs, sums[s]);
		}
		int res = 0;
		for (int i = 0; i < 37; i++) {
			if(sums[i] == mxs) {
				res++;
			}
		}
		return res;
	}
};