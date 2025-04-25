#include <bits/stdc++.h>

class Solution {
	std::string make_str(int num, int digits) {
		std::string res = std::to_string(num);
		int n = res.size();
		for (int i = 0; i < digits - n; i++)
		{
			res = '0' + res;
		}
		return res;
	}
	std::unordered_set<std::string> all_changes(int num, int digit) {
		std::unordered_set<std::string> res;
		std::string str = make_str(num, digit);
		res.insert(str);
		for (int i = 0; i < digit; i++)
		{
			for (int j = i + 1; j < digit; j++)
			{
				std::swap(str[i], str[j]);
				res.insert(str);
				for (int i1 = 0; i1 < digit; i1++)
				{
					for (int j1 = i1 +1; j1 < digit; j1++)
					{
						if(str[i1] != str[j1]) {
							std::swap(str[i1], str[j1]);
							res.insert(str);
							std::swap(str[i1], str[j1]);
						}
					}
				}
				std::swap(str[i], str[j]);
			}
		}
		return res;
	}
public:
	int countPairs(std::vector<int>& nums) {
		int n = nums.size();
		int digit = std::to_string(*std::max_element(nums.begin(), nums.end())).size();
		int ans = 0;
		std::unordered_map<std::string, int> similar;
		for (int i = 0; i < n; i++)
		{
			for (auto chang: all_changes(nums[i], digit))
			{
				ans += similar[chang];
			}
			similar[make_str(nums[i], digit)]++;
		}
		return ans;
	}
};