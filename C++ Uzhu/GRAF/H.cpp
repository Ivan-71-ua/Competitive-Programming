#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
//#define int long long

int32_t main() {
	fast;
	int n, k;
	std::cin >> n >> k;
	std::map<int, std::set<int>> list_smesh;
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
		} else if(tp == 2) {
			int a;
			std::cin >> a;
			if(list_smesh.count(a)) {
				for(auto now: list_smesh[a]) {
					std::cout << now << " ";
				}
				std::cout << '\n';
			} 
		}
	}
}