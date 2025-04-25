#include <bits/stdc++.h>

	class Solution {
	public:
		void rotate(std::vector<int>& nums, int k) {
			int kk = k % nums.size();
			std::vector<int> tp(nums.begin(), nums.end());
			for (int i = 0; i < nums.size(); i++)
			{
				nums[(i + kk) % nums.size()] = tp[i];
			}
			
		}
	};

int main() {
	Solution ans;
	std::vector<int> ss{1, 2, 3, 4, 5, 6, 7};
	ans.rotate(ss, 3);
}