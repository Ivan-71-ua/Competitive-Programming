
#include <bits/stdc++.h>




class Solution {
public:
	long long continuousSubarrays(std::vector<int>& nums) {
		long long res = 0;
		int maxs = 0, mins = INT32_MAX;
		int l = 0;
		std::map<int, int> cnt;
		for (int r = 0; r < nums.size(); r++) {
			maxs = std::max(maxs, nums[r]);
			mins = std::min(mins, nums[r]);
			cnt[nums[r]]++;
			while(abs(maxs - mins) > 2) {
				cnt[nums[l]]--;
				if(cnt[nums[l]] == 0)
					cnt.erase(nums[l]);
				l++;
				maxs = (int)cnt.rbegin()->first;
				mins = (int)cnt.begin()->first;
			}
			res += r - l + 1;
		}
		return res;
	}
};


int main() {
	Solution ans;
	std::vector<int> ss{5, 4, 2, 4};
	ans.continuousSubarrays(ss);
}