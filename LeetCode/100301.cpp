#include <bits/stdc++.h>


class Solution {
public:
	long long countCompleteDayPairs(std::vector<int>& hours) {
		long long res = 0;
		std::unordered_map<int, int> hash;
		for (int i = 0; i < hours.size(); i++)
		{
			int tmp = (24 - (hours[i] % 24)) % 24;
			if(hash.count(tmp)) {
				res += hash[tmp];
			}
			hash[hours[i] % 24]++;
		}
		return res;
	}
};