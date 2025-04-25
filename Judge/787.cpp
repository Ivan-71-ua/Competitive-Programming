

#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <cstdint>
/*
void solve(std::vector<int> &nums)
{
	long long cur_max = nums[0];
	long long cur_min = nums[0];
	long long sum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if(nums[i] < 0) {
			std::swap(cur_max, cur_min);
		}
		cur_max = std::max((long long)nums[i], nums[i] * cur_max);
		cur_min = std::min((long long)nums[i], nums[i] * cur_min);
		sum = std::max(sum, cur_max);
	}
	std::cout << sum << '\n';
}

int main() {
	int tmp;
	std::vector<int> nums;
	while(std::cin >> tmp) {
		if(tmp == -999999) {
			solve(nums);
			nums.clear();
		} else {
			nums.push_back(tmp);
		}
	}
}
*/

void solve1(const std::vector<int> &nums) {
	long long max_product = INT32_MIN;  
	long long cur_max = 1;  
	long long cur_min = 1;

	for (int num : nums) {
		if (num == 0) {
			
			cur_max = 1;
			cur_min = 1;
			max_product = std::max(max_product, 0LL);  
			continue;
		}

		long long temp_max = cur_max * num;
		long long temp_min = cur_min * num;

		cur_max = std::max({(long long)num, temp_max, temp_min});
		cur_min = std::min({(long long)num, temp_max, temp_min});

		max_product = std::max(max_product, cur_max);
	}

	std::cout << max_product << '\n';
}

void solve2(const std::vector<int> &nums) {
	long long max_product = nums[0];  
	long long cur_max = nums[0];  
	long long cur_min = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == 0) {
			cur_max = 1;
			cur_min = 1;
			max_product = std::max(max_product, 0LL);  
			continue;
		}

		long long temp_max = cur_max * nums[i];
		long long temp_min = cur_min * nums[i];

		cur_max = std::max({(long long)nums[i], temp_max, temp_min});
		cur_min = std::min({(long long)nums[i], temp_max, temp_min});

		max_product = std::max(max_product, cur_max);
	}

	std::cout << max_product << '\n';
}

int main() {
	int tmp;
	std::vector<int> nums;

	while (std::cin >> tmp) {
		if (tmp == -999999) {
			solve2(nums);
			nums.clear();
		} else {
			nums.push_back(tmp);
		}
	}

	return 0;
}