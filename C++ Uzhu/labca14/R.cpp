#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long



int32_t main() {
	fast;
	int n, k;
	std::cin >> n >> k;
	std::vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> res[i];
	}
	int ans = -1;
	int tmp = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		tmp += res[i];
		while (tmp > k)
		{
			tmp -= res[j];
			j++;
		}
		ans = std::max(ans, tmp);
	}
	std::cout << ans;
}