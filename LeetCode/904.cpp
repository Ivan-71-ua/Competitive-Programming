#include <bits/stdc++.h>


class Solution {
public:
	int totalFruit(std::vector<int>& fruits) {
		std::unordered_map<int, int> cnt;
		int res = 0;
		int l = 0;
		for (int r = 0; r < fruits.size(); r++) {
			cnt[fruits[r]]++;
			while(cnt.size() > 2) {
				cnt[fruits[l]]--;
				if(cnt[fruits[l]] == 0)
					cnt.erase(fruits[l]);
				l++;
			}
			res = std::max(res, r - l + 1);
		}
		return res;
	}
};