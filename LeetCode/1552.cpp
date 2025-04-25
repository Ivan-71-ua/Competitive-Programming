#include <bits/stdc++.h>




class Solution {
	bool can(int m, std::vector<int>& position, int dist) {
		int prev = position[0];
		m--;
		for (int i = 1; i < position.size() && m > 0; i++) {
			if(position[i] - prev >= dist) {
				m--;
				prev = position[i];	
			}
		}
		return m == 0;
	}
public:
	int maxDistance(std::vector<int>& position, int m) {
		std::sort(position.begin(), position.end());
		int i = 1, j = position.back() - 1;
		int ans = 0;
		while(i < j) {
			long long mid = (i + j) / 2;
			if(can(m, position, mid)) {
				ans = mid;
				i = mid + 1;
			} else {
				j = mid - 1;
			}
		}
		return ans;
	}
};