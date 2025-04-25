#include <bits/stdc++.h>

class Solution {
public:
   bool canPartition(std::vector<int>& nums) {
		int n = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			n += nums[i];
		}
		if(n % 2 != 0)
			return false;
		std::set<int> all_sum;
		all_sum.insert(0);
		for (int i = 0; i < nums.size(); i++)
		{
			std::set<int> tp_set;
			for (auto now : all_sum)
			{
				if(now + nums[i] == n /2)
					return true;
				tp_set.insert(now);
				tp_set.insert(now + nums[i]);
			}
			all_sum = tp_set;
		}
		return all_sum.count(n / 2);
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{1, 5, 11, 5};
	ans.canPartition(ss);
}
