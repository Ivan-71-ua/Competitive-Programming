#include <bits/stdc++.h>

	class Solution {
	public:
		void rotate(std::vector<int>& nums, int k) {
			int kk = k % nums.size();
			std::vector<int> tp(nums.begin(), nums.end());
			int i = 0;
			for (; i < kk; i++)
			{
				nums[i] = tp[tp.size() - kk + i];
			}
			for (int j = 0; j < nums.size() - kk; i++, j++)
			{
				nums[i] = tp[j];
			}
		}
	};

int main() {
	Solution ans;
	std::vector<int> ss{1, 2, 3, 4, 5, 6, 7};
	ans.rotate(ss, 3);
}