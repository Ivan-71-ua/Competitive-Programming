#include <bits/stdc++.h>

class Solution {
public:
	int findShortestSubArray(std::vector<int>& nums) {
		std::unordered_map<int, int> quant;
		std::unordered_map<int, std::pair<int, int>> cord;
		//std::set<int> sets(nums.begin(), nums.end());
		int max = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			quant[nums[i]]++;
			if(cord[nums[i]].first == 0 && quant[nums[i]] == 1) {
				cord[nums[i]].first = i;
				cord[nums[i]].second = i;
			} else {
				cord[nums[i]].second = i;
			}
			max = std::max(max, quant[nums[i]]);
		}
		int res = INT32_MAX;
		/*
		for (auto now: sets)
		{
			if(quant[now] == max) {
				res = std::min(res, cord[now].second - cord[now].first + 1);
			}
		}
		*/
	for (int i = 0; i < nums.size(); i++)
	{
		if(quant[nums[i]] == max) {
			res = std::min(res, cord[nums[i]].second - cord[nums[i]].first + 1);
		}
	}
	return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> res{1, 1};
	ans.findShortestSubArray(res);
}