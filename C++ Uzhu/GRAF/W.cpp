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
	bool is = true;
	for (int i = 2; i <= n; i++)
	{
		if(reb[i -1] != reb[i]) {
			is = false;
			break;
		}
	}
	if(is) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}