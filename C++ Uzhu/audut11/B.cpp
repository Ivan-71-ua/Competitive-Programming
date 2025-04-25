#include <bits/stdc++.h>
#define ll long long

int main() {
	int n, m, x;
	std::cin >> n >> m;
	int s[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			s[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			std::cin >> s[i][j];
		}

	}
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll x, y, x1, y1;
		ll sum = 0;
		std::cin >> x >> y >> x1 >> y1;
		for (int p = x; p <= x1; p++)
		{
			for (int j = y; j <= y1; j++)
			{
				sum += s[p][j];

			}
		}
      std::cout << sum << '\n';
	}
}