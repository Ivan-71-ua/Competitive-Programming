#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	int n, res = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tp;
			std::cin >> tp;
			if(tp == 1)
				res++;
		}
	}
	std::cout << res;
}