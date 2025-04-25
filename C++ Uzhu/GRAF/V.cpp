#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> reb(n +1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		reb[a]++;
		reb[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		std::cout << reb[i] << '\n';
	}
	
}