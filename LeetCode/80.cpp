#include <bits/stdc++.h>

class Solution {
public:
   int removeDuplicates(std::vector<int>& nums) {
		int l = 0;
		int r = 0;
		while(r < nums.size()) {
			int count = 1;
			while(nums[r +1] < nums.size() && nums[r + 1] == nums[r]) {
				count++;
				r++;
			}
			int k = std::min(2, count);
			while(k--) {
				nums[l] = nums[r];
				l++;
			}
			r++;
		}
		return l;
	}
};

int main() {
	Solution an;
	std::vector<int> ll{0, 0, 1, 1, 1, 1, 2, 3, 3};
	an.removeDuplicates(ll);
}