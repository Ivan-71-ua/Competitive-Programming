#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	std::vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if(nums[i] > nums[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end());
}