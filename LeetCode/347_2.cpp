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
		std::unordered_map <int, std::vector<int>>cout_val;
		for (auto cv : val_quan) {
			cout_val[cv.second].push_back(cv.first);
		}
		std::vector<int> freq;
		for (auto cv : cout_val) {
			freq.push_back(cv.first);
		}
		std::sort(freq.begin(), freq.end(), std::greater());
		for (int f : freq)
		{
			for (auto key : cout_val[f])
			{
				ans.push_back(key);
				if(ans.size() == k) {
					return ans;
				}
			}
			
		}
		throw _invalid_parameter_handler ("not k qrek");
	}
};

int main() {
	Solution ans;
	std::vector<int> nums{3, 0, 1, 0};
	ans.topKFrequent(nums, 1);
}