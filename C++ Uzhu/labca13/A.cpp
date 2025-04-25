#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	std::vector<int> one(t);
	std::vector<int> two(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> one[i];
	}
	for (int i = 0; i < t; i++)
	{
		std::cin >> two[i];
	}
	std::sort(one.begin(), one.end());
	std::sort(two.begin(), two.end(), std::greater());
	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		ans += one[i] * two[i];
	}
	std::cout << ans;
}