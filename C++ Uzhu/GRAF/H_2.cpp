#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define intvlonh long

int main() {
	fast;
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> list_smesh(n + 1);
	for (int i = 0; i < k; i++)
	{
		int tp;
		std::cin >> tp;
		if(tp == 1) {
			int a, b;
			std::cin >> a >> b;
			list_smesh[a].push_back(b);
			list_smesh[b].push_back(a);
		} else {
			int a;
			std::cin >> a;
			for (int j = 0; j < list_smesh[a].size(); j++)
			{
				std::cout << list_smesh[a][j] << " ";
			}
			std::cout << '\n';
			
		}
	}
}