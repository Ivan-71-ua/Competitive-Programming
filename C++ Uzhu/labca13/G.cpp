#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	std::vector<int> cow(t);
	std::vector<int> home(t);
	std::vector<int> dp(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> cow[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cin >> home[i];
	}
	std::sort(cow.begin(), cow.end(), std::greater());
	std::sort(home.begin(), home.end(), std::greater());
	int ans = 1;
	for (int i = t -1; i >=0 ; i--)
	{
		for (int j = 0; j < t; j++)
		{
				if(home[i] >= cow[j])
					dp[t - i - 1]++;
		}
	}
	int k = 0;
	for (int i = 0; i < t; i++)
	{
		ans *= dp[i] - k;
		k++;
	}
	std::cout << ans;
}