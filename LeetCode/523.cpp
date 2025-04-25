#include <bits/stdc++.h>

class Solution {
public:
   bool checkSubarraySum(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> pref_quant;
		pref_quant[0] = -1;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			sum %= k;
			if(pref_quant.count(sum)) {
				if(i - pref_quant[sum] > 1) return true;
			}
			else {
				pref_quant[sum] = i;
			}
		}
		return false;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums{422, 224, 184, 178, 189, 290, 196, 236, 281, 464, 351, 193, 49, 76, 0, 298, 193, 176, 158, 514, 312, 143, 475, 322, 206, 67, 524, 424, 76, 99, 473, 256, 36, 4, 292, 141, 186, 190, 69, 433, 205, 93, 72, 476, 393, 512, 468, 160, 201, 226, 394, 47, 140, 389, 51, 142, 135, 349, 244, 16, 356, 440, 188, 16, 133, 58, 394, 7, 517, 56, 480, 400, 146, 169, 439, 102, 374, 370, 242, 4, 264, 120, 218, 196, 173, 215, 411, 501, 321, 319, 147, 369, 458, 319, 174, 379, 46, 129, 353, 33, 0, 101};

	std::cout << ans.checkSubarraySum(nums,479);
}