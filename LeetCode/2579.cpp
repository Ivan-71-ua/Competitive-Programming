#include <bits/stdc++.h>


class Solution {
public:
	long long coloredCells(int n) {
		class Solution {
			public:
				long long coloredCells(int n) {
					n = (long long)n;
					long long square = (long long)(1 + (n - 1) * 2) * (1 + (n - 1) * 2);
					long long dels = ((long long)n * n) - ((n * (n + 1LL)) / 2LL);
					return square - 4 * dels;
				}
			};
	}
};