#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> nums(n - 1);
		for (int i = 0; i < n -1; i++)
		{
			std::cin >> nums[i];
		}
		if(n == 1) {
			std::cout << nums[0] << ' ' << nums[0] << '\n';
		} else {
			std::vector<int> ans(n);
			ans[0] = nums[0];
			ans.back() = nums.back();
			for (int i = 0; i < nums.size() - 1; i++)
			{
				ans[i + 1] = nums[i] | nums[i + 1];
			}
			bool is = false;
			for (int i = 0; i < nums.size(); i++)
			{
				if(nums[i] != ans[i] ^ ans[i +1]) {
					is = true;
					break;
				}
			}
			if(is) {
				std::cout << -1 << '\n';
			} else {
				for (auto now: ans)
				{
					std::cout << now << ' ';
				}
				std::cout << '\n';
			}
		}
	}
}