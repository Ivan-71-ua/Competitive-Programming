#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> matrx(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrx[i][j];
		}
	}
	std::set<int> stoc;
	std::set<int> istoc;
	for (int i = 0; i < n; i++)
	{
		bool is = true;
		for (int j = 0; j < n; j++)
		{
			if(matrx[j][i] == 1) {
				is = false;
				break;
			}
		}
		if(is) {
			stoc.insert(i + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		bool is = true;
		for (int j = 0; j < n; j++)
		{
			if(matrx[i][j] == 1) {
				is = false;
				break;
			}
		}
		if(is) {
			istoc.insert(i + 1);
		}
	}
	std::cout << stoc.size() << ' ';
	for (auto now: stoc)
	{
		std::cout << now << ' ';
	}
	std::cout << '\n';
	std::cout << istoc.size() << ' ';
	for (auto now: istoc)
	{
		std::cout << now << ' ';
	}
}