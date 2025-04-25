
#include <bits/stdc++.h>

int32_t main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		int max = i;
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if(nums[max] < nums[j]) {
				max = j;
			}
			if(nums[min] > nums[i]) {
				min = j;
			}
			if(max > min) {
				res++;
			}
		}
	}
	std::cout << res << '\n';
}