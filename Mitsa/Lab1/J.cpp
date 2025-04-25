#include <bits/stdc++.h>


int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> matrx(n + 1);
	for (int i = 0; i < n; i++)
	{
		int k;
		std::cin >> k;
		while (k--)
		{
			int t;
			std::cin >> t;
			matrx[t]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if(matrx[i] == 0)
			res++;
	}
	std::cout << res;
}