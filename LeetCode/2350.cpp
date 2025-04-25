#include <bits/stdc++.h>


class Solution {
public:
	int shortestSequence(std::vector<int>& rolls, int k) {
		std::set<int> nums;
		int ans = 1;
		for (int i = 0; i < rolls.size(); i++)
		{
			nums.insert(rolls[i]);
			if(nums.size() == k) {
				ans++;
				nums.clear();
			}
		}
		return ans;
	}
};