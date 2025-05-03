#include <bits/stdc++.h>

class Solution {
	public:
		int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
				std::ios::sync_with_stdio(false);
			std::cin.tie(nullptr);      
			std::cout.tie(nullptr);
			int res = INT_MAX, n = tops.size();
			std::vector<int> s1(7, 0), s2(7, 0);
			for (int i = 0; i < n; i++) {
				s1[tops[i]]++;
				s2[bottoms[i]]++;
			}
			for (int i = 1; i < 7; i++) {
				if(s1[i]) {
					int cnt = 0, swap = 0;
					for (int j = 0; j < n; j++) {
						if(tops[j] == i) {
							cnt++;
						} else if(bottoms[j] == i) {
							cnt++;
							swap++;
						}
					}
					if(cnt == n) {
						res = std::min(res, swap);
					}
				}
				if(s2[i]){
					int cnt = 0, swap = 0;
					for (int j = 0; j < n; j++) {
						if(bottoms[j] == i) {
							cnt++;
						} else if(tops[j] == i) {
							cnt++;
							swap++;
						}
					}
					if(cnt == n) {
						res = std::min(res, swap);
					}
				}
			}
			if(res == INT_MAX) return -1;
			return res;
		}
	};