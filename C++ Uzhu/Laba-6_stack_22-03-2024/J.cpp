#include <bits/stdc++.h>


const int MOD = 1e9 + 7;

int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}
	std::vector<int> left(n, -1);
	std::vector<int> right(n, n);
	std::stack<int> stk;
	for (int i = 0; i < n; ++i) {
		while (!stk.empty() && nums[stk.top()] >= nums[i]) {
				stk.pop();
		}
		if (!stk.empty()) {
				left[i] = stk.top();
		}
		stk.push(i);
	}
	
	while(!stk.empty()) stk.pop(); 
	for (int i = n - 1; i >= 0; --i) {
		while (!stk.empty() && nums[stk.top()] > nums[i]) {
				stk.pop();
		}
		if (!stk.empty()) {
				right[i] = stk.top();
		}
		stk.push(i);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += static_cast<int>((long long)(i - left[i]) * (right[i] - i) * nums[i] % MOD);
		sum %= MOD;
	}
	std::cout << sum << std::endl;
	
}
