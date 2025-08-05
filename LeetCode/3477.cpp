

#include <bits/stdc++.h>



class Solution {
public:
	int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
		int n = fruits.size(), cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(baskets[j] && fruits[i] <= baskets[j]) {
					cnt++;
					baskets[j] = 0;
					break;
				}
			}
		}
		return n - cnt;
	}
};