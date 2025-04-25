#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	int n;
	std::cin >> n;
	int res = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tp;
			std::cin >> tp;
			if(j > k && tp == 1) {
				res++;
			}
		}
		k++;
	}
	std::cout << res;
}