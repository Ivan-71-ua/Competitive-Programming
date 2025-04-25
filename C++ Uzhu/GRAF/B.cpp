#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



int main() {
	fast;
	int n, m;
	std::cin >> n >> m;
	//std::set<int> list_V;
	std::vector<std::pair<int, int>> list_E(m);
	for (int i = 0; i < m; i++)
	{
		int u, k;
		std::cin >> u >> k;
		list_E[i] = {u, k};
		//list_V.insert(u);
		//list_V.insert(k);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(i + 1 == list_E[j].first || i + 1 == list_E[j].second) {
				std::cout << 1 << ' ';
			} else {
				std::cout << 0 << ' ';
			}
		}
		std::cout << '\n';
	}
	
}