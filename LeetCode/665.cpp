#include <bits/stdc++.h>

	class Solution {
	public:
		bool checkPossibility(std::vector<int>& nums) {
			if(nums.size() < 3)
				return true;
			int line = 0;
			int was = -1;
			for (int i = 1; i < nums.size(); i++)
			{
				if(nums[i -1] > nums[i]) {
					line++;
					was = i - 1;
				}
				if(line > 1)
					return false;
			}
			if(line == 1) {
				if(was == 0 || was == nums.size() -2)
				return true;
				if(nums[was + 1] >= nums[was-1]) {
					return true;
				} else {
					if(nums[was] <= nums[was  + 2])
						return true;
					return false;
				}
			}
			return true;
		}
	};

int main() {
	Solution asn;
	std::vector<int> nums{5,7,1,8};
	asn.checkPossibility(nums);
}