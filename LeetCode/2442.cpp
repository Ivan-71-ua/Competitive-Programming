#include <bits/stdc++.h>


class Solution {
public:
	int countDistinctIntegers(std::vector<int>& nums) {
		std::set<int> res(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			std::string tmp;
			while(nums[i]) {
				tmp += ('0' + nums[i] % 10);
				nums[i] /= 10;
			}
			res.insert(std::stoi(tmp));
		}
		return res.size();
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 13, 10, 12, 31};
	ans.countDistinctIntegers(ss);
}