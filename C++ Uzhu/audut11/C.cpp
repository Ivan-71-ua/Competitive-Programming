#include <bits/stdc++.h>
#define ll long long

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	int s[n + 1][m + 1][k + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int p = 1; p <= k; p++)
			{
				std::cin >> s[i][j][p];
			}
			
		}
	}
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll x, y, x1, y1, z,z1;
		ll sum = 0;
		std::cin >> x >> y >> z >> x1 >> y1 >> z1;
		for (int p = x; p <= x1; p++)
		{
			for (int j = y; j <= y1; j++)
			{
				for (int o = z; o <= z1; o++)
				{
					sum += s[p][j][o];
				}
			}
		}
      std::cout << sum << '\n';
	}
}