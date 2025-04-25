#include <bits/stdc++.h>



class Solution {
	int cout(long long cur, long long n) {
	long long res = 0;
	long long neig = cur + 1;
	while(cur <= n) {
		res += std::min(n + 1, neig) - cur;
		cur *= 10;
		neig *= 10;
	}
	return res;
}
public:
	int findKthNumber(int n, int k) {
		int i = 1;
		long long cur = 1;
		while(i < k) {
			int step = cout(cur, n);
			if(i + step <= k) {
				cur = cur +1;
				i += step;
			} else {
				cur *= 10;
				i++;
			}
		}
		return cur;
	}
};