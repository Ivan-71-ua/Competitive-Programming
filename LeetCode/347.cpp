#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::vector<int> ans;
		std::unordered_map<int, int> val_quan;
		for (int i = 0; i < nums.size(); i++)
		{
			val_quan[nums[i]]++;
		}
		for (int i = 0; i < k; i++)
		{
			int val, quan =-1;
			for (auto it = val_quan.begin(); it != val_quan.end(); it++)
			{
				if(it->second > quan) {
					val = it->first;
					quan = it->second;
				}
			}
			ans.push_back(val);
			val_quan.erase(val);
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums{3, 0, 1, 0};
	ans.topKFrequent(nums, 1);
}