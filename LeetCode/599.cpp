#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
		std::unordered_map<std::string, int> list_of_one;
		std::unordered_map<std::string, int> list_of_two;
		int min = INT32_MAX;
		for (int i = 0; i < list1.size(); i++)
		{
			list_of_one[list1[i]] = i;
		}
		for (int i = 0; i < list2.size(); i++)
		{
			list_of_two[list2[i]] = i;
		}
		std::map<int, std::vector<std::string>> res;
		for (auto now: list_of_one)
		{
			if(list_of_two.count(now.first)) {
				res[now.second + list_of_two[now.first]].push_back(now.first);
			}
		}
		return res.begin()->second;
	}
};