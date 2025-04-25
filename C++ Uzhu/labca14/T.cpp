#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long




int32_t main() {
	int target, n;
	std::cin >> n >> target;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	std::vector<std::vector<int>> result;
	if (n < 3) {
		std::cout << -1;
		return 0;
	}
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; i++) {
		if (nums[i] > target) {
			break;
		}
		if (i > target && nums[i - 1] == nums[i]) {
			continue;
		}
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (sum < target) {
				j++;
			} else if (sum > target) {
					k--;
			} else {
				result.push_back({nums[i], nums[j], nums[k]});
				while (j < k && nums[j] == nums[j + 1]) {
					j++;
				}
				j++;
				while (j < k && nums[k - 1] == nums[k]) {
					k--;
				}
				k--;
			}
		}
	}
	if(result.empty()) {
		std::cout << -1;
	} else {
		std::cout << result[0][0] << ' ' << result[0][1] << ' ' <<  result[0][2];
	}
}