#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> summaryRanges(std::vector<int>& nums) {
		if(nums.size() == 1)
			return {std::to_string(nums[0])};
		std::vector<std::string> ans;
		int st = 0, fn= 0;
		for (int i = 1; i <= nums.size(); i++)
		{
			if(i != nums.size() && (long long)nums[i] - nums[i-1] == 1) {
				continue;
			} else {
				fn = i - 1;
				if(st == fn) {
					std::string res;
					res = std::to_string(nums[st]);
					ans.push_back(res);
				} else {
					std::string res = std::to_string(nums[st]) + "->" + std::to_string(nums[fn]);
					ans.push_back(res);
				}
				st = i;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{-2147483648,-2147483647,2147483647};
	ans.summaryRanges(ss);
}
