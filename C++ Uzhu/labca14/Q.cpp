#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	int n, k;
	std::cin >> n >> k;
	int ans = -1;
	std::vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> res[i];
	}
	std::stable_sort(res.begin(), res.end());
	for (int i = 0; i < n; i++)
	{
		int tp = 0;
		for (int j = i; j < n; j++)
		{
			if(res[j] > k + res[i]) {
				break;
			}
			tp++;
		}
		ans = std::max(ans, tp);
	}
	std::cout << ans;
}