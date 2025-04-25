#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<std::multiset<int>> matrx(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tp;
			std::cin >> tp;
			if(tp != 0) {
				matrx[i].insert(j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << matrx[i].size() << ' ';
		for(auto now:matrx[i]) {
			std::cout << now << ' ';
		}
		std::cout << '\n';
	}
}