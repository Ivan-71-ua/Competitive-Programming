
#include <bits/stdc++.h>



class Solution {
public:
	int maxDistance(std::string s, int k) {
		int n = s.size(), N = 0, S = 0, W = 0, E = 0, ans = 0;
		for(char c : s) {
			if (c == 'N') {
				N++;
			} else if( c == 'S') {
				S++;
			} else if (c == 'W') {
				W++;
			} else if (c == 'E') {
				E++;
			}
			int dk = k;
			int xs = abs(N - S) + std::min({N, S, dk}) * 2;
			dk = std::max(0, k - std::min(N, S));
			int ys = abs(W - E) + std::min({E, W, dk}) * 2;
			ans = std::max(ans, xs + ys);
		}
		return ans;
	}
};