#include <bits/stdc++.h>



int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	bool pair = true;
	int prev = std::gcd(nums[0], nums[1]);
	for (int i = 1; i < n; i++)
	{
		int tmp = std::gcd(nums[i - 1], nums[i]);
		if(tmp != 1)
			pair = false;
		if(i > 1)
			prev = std::gcd(prev, nums[i]);
	}
	if(pair) {
		std::cout << "pairwise coprime\n";
		return 0;
	}
	if(prev == 1) {
		std::cout << "setwise coprime\n";
	} else {
		std::cout << "not coprime\n";
	}
}