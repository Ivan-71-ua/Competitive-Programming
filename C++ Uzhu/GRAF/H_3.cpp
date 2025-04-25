#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	fast;
	int n, k;
	std::cin >> n >> k;
	std::vector<std::set<int>> list_smesh(n + 1);
	for (int i = 0; i < k; i++)
	{
		int tp;
		std::cin >> tp;
		if(tp == 1) {
			int a, b;
			std::cin >> a >> b;
			if(a == b) {
				continue;
			}
			list_smesh[a].insert(b);
			list_smesh[b].insert(a);
		} else {
			int a;
			std::cin >> a;
			for (auto now:list_smesh[a])
			{
				std::cout << now << " ";
			}
			std::cout << '\n';
		}
	}
}