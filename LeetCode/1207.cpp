#include <bits/stdc++.h>


class Solution {
public:
	bool uniqueOccurrences(std::vector<int>& arr) {
		std::map<int, int> dig_count;
		for (auto num: arr)
		{
			dig_count[num]++;
		}
		std::set<int> unic_count;
		for (auto now: dig_count)
		{
			if(unic_count.count(now.second))
				return false;
			unic_count.insert(now.second);
		}
		return true;
	}
};


