
#include <bits/stdc++.h>


class Solution {
public:
	int totalFruit(std::vector<int>& fruits) {
		std::pair<int, int> first{-1, 0}, second{-1, 0};
		int res = 0;
		for (int i = 0; i < fruits.size(); i++)
		{
			if(first.first == -1 || first.first == fruits[i]) {
				first.first = fruits[i];
				first.second++;
			} else if(second.first == -1 || second.first == fruits[i]) {
				second.first = fruits[i];
				second.second++;
				std::swap(first, second);
			} else {
				int cnt = 0, idx = i - 1;
				while(idx  > -1 && fruits[idx] == second.first) {
					cnt++;
					idx--;
				}
				first.second = cnt;
				second.first = fruits[i];
				second.second = 1;
				std::swap(first, second);
			}
			res = std::max(res, first.second + second.second);
		}
		return res;
	}
};
