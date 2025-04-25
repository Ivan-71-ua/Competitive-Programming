#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::set<std::pair<int, int>> reb;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		reb.insert(std::make_pair(a, b));
	}
	if(reb.size() == m)
		std::cout << "NO";
	else
		std::cout << "YES";
}