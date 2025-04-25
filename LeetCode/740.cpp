#include <bits/stdc++.h>

class Solution {
public:
   int deleteAndEarn(std::vector<int>& nums) {
		std::map<int, int> num_quan;
		for (int i = 0; i < nums.size(); i++)
		{
			num_quan[nums[i]]++;
		}
		if(num_quan.size() == 1) {
			return num_quan.begin()->first * num_quan.begin()->second;
		}
		std::vector<int> tp(num_quan.rbegin()->first + 1);
		for (int i = 0; i < num_quan.rbegin()->first + 1; i++)
		{
			if(num_quan.count(i))
				tp[i] = i * num_quan[i];
			else
				tp[i] = 0;
		}
		int was = 0;
		int cur = 0;
		for (int i = 0; i < tp.size(); i++)
		{
			int next = std::max(was + tp[i], cur);
			was = cur;
			cur = next;
		}
		return cur;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{2, 2, 3, 3, 3, 4};
	ans.deleteAndEarn(ss);
}