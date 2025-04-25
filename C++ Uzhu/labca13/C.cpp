#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	int t;
	std::cin >> t;
	std::vector<int> prise(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> prise[i];
	}
	std::sort(prise.begin(), prise.end(), std::greater());
	int ans = 0;
	for (int i = 0; i  < t; i++)
	{
		if(i % 3 != 2) {
			ans += prise[i];
		}
	}
	std::cout << ans;
}