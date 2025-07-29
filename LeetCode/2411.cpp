
#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> smallestSubarrays(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ans(n, 0);
		std::vector<int> last_bit(32, -1);
		for (int i = n - 1; i > -1; i--) {
			int8_t bit = 0;
			while(bit < 32) {
				if(nums[i] & (1 << bit)) {
					last_bit[bit] = i;
				}
				bit++;
			}
			int idx = i;
			for (int i = 0; i < 32; i++) {
				idx = std::max(idx, last_bit[i]);
			}
			ans[i] = idx - i + 1;
		}
		return ans;
	}
};