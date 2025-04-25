#include <bits/stdc++.h>



class Solution {
public:
	std::string findDifferentBinaryString(std::vector<std::string>& nums) {
		std::set<long long> num;
		for (auto &now: nums)
		{
			num.insert(std::stoi(now, nullptr, 2));
		}
		for (int i = 0; i < 1 << nums[0].size(); i++)
		{
			if(!num.count(i)) {
				return std::bitset<32>(i).to_string().substr(32 - nums[0].size());
			}
		}
		return "";
	}
};