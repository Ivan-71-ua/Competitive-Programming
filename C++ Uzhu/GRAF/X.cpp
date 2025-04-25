#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n;
	std::vector<int> reb(n +1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			std::cin >> a;
			if(a==1) {
				reb[i]++;
			}
		}
		
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if(reb[i] ==1) {
			res++;
		}
	}
	std::cout << res;
}