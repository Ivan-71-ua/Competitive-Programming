#include <bits/stdc++.h>
#define ll long long


int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> nums[i];
		}
		int res = -1;
		for (int i = 0; i < n; i+= 2)
		{
			res = std::max(res, nums[i]);
		}
		std::cout << res << '\n';
	}
}