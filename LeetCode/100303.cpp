#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> occurrencesOfElement(std::vector<int>& nums, std::vector<int>& queries, int x) {
		std::unordered_map<int, int> pleses_x;
		int k = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == x) {
				pleses_x[k++] = i;
			}
		}
		std::vector<int> res(queries.size());
		for (int i = 0; i < queries.size(); i++)
		{
			if(pleses_x.count(queries[i])) {
				res[i] = pleses_x[queries[i]];
			} else {
				res[i] = -1;
			}
		}
		return res;
	}
};