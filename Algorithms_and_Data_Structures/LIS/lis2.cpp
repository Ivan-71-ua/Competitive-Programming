#include <bits/stdc++.h>


int get_max_lis(std::vector<int> list) {
	int n = list.size();
	std::vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(list[j] < list[i]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

int main() {
	std::vector<int> s{3, 2, 4, 1, 6, 5, 8, 4, 9, 7};
	std::vector<int> st{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> sk{8, 7, 6, 5, 4, 3, 2, 1};
	std::cout << get_max_lis(st);
}