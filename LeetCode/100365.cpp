#include <bits/stdc++.h>

class Solution {
public:
	int minChanges(std::vector<int>& nums, int k) {
		std::vector<int> freq(k + 1);
		std::vector<int> v;
		int n = nums.size();
		for (int i = 0; i < n / 2; i++) {
			int dif = std::abs(nums[i] - nums[n - i - 1]);
			freq[dif]++;

			int a = nums[i], b = nums[n - i - 1];
			int threshold = std::max(std::max(a, b), k - std::min(a, b));
			v.push_back(threshold);
		}

		std::sort(v.begin(), v.end());

		int ans = n / 2;
		n /= 2;
		for (int i = 0; i < freq.size(); i++) {
			int rest = n - freq[i];
			int less_than_diff = std::lower_bound(v.begin(), v.end(), i) - v.begin();
			ans = std::min(ans, rest + less_than_diff);
		}
		return ans;
	}
};

int main() {
	Solution sol;
	std::vector<int> nums1 = {1, 0, 1, 2, 4, 3};
	int k1 = 4;
	std::cout << sol.minChanges(nums1, k1) << std::endl;

	std::vector<int> nums2 = {0, 1, 2, 3, 3, 6, 5, 4};
	int k2 = 6;
	std::cout << sol.minChanges(nums2, k2) << std::endl;

	std::vector<int> nums3 = {1, 1, 1, 1, 0, 0, 0, 5, 4, 3, 19, 17, 16, 15, 15, 15, 19, 19, 19, 19};
	int k3 = 20;
	std::cout << sol.minChanges(nums3, k3) << std::endl;

	return 0;
}
