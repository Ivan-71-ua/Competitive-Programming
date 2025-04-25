
#include <bits/stdc++.h>


class Solution {
public:
	int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
		int pref = 0;
		std::map<int, int> count_a1;
		for (auto now: arr1)
		{
			while(now) {
				count_a1[now]++;
				now /= 10;
			}
		}
		for (auto now: arr2)
		{
			while(now) {
				if(count_a1.count(now)) {
					pref = std::max(pref, now);
				}
				now /= 10;
			}
		}
		int size = 0;
		while(pref) {
			size++;
			pref /= 10;
		}
		return size;
	}
};