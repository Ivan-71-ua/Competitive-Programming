#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
		std::vector<int> ans;
		std::set<int> val;
		for (int i = 0; i < nums.size(); i++)
		{
			val.insert(nums[i]);
		}
		for (int i = 1; i <= nums.size(); i++)
		{
			if(!val.count(i))
				ans.push_back(i);
		}
		
		
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> val{4, 3, 2, 7, 8, 2, 3, 1};
	ans.findDisappearedNumbers(val);
}