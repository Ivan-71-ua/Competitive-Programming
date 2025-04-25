#include <bits/stdc++.h>

int get_max_lis(std::vector<int> list) {
	int n = list.size();
	std::vector<int> sorted_list(list.begin(), list.end());
	std::stable_sort(sorted_list.begin(), sorted_list.end());
	std::vector<std::vector<int>>dp(n + 1, std::vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(sorted_list[i - 1] == list[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][n];
}


int main() {
	std::vector<int> s{3, 2, 4, 1, 6, 5, 8, 4, 9, 7};
	std::vector<int> st{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> sk{8, 7, 6, 5, 4, 3, 2, 1};
	std::cout << get_max_lis(sk);
}