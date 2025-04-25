#include <bits/stdc++.h>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> prise(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> prise[i];
	}
	std::stable_sort(prise.begin(), prise.end(),std::greater());
	int k = std::min(n,m);
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		res += prise[i];
	}
	std::cout << res;
}