#include <bits/stdc++.h>




class Solution {
public:
	int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
		int cnt = 0, n = fruits.size();
		int m = sqrt(n);
		int num_sect = (n + m - 1) / m;
		std::vector<int> sections(num_sect);
		for (int i = 0; i < n; i++) {
			sections[i / m] = std::max(sections[i / m], baskets[i]);
		}
		for (int i = 0; i < n; i++) {
			int find = 1;
			for (int j = 0; j < num_sect; j++) {
				if(sections[j] < fruits[i]) continue;
				bool choose = false;
            sections[j] = 0;
				for (int k = 0; k < m; k++) {
					int pos = j * m + k;
					if (pos < n && baskets[pos] >= fruits[i] && !choose) {
						choose = true;
						baskets[pos] = 0;
					}
					if(pos < n) {
						sections[j] = std::max(sections[j], baskets[pos]);
					}
				}
				find = 0;
            break;
			}
			cnt += find;
		}
		return cnt;
	}
};