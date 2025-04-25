#include <bits/stdc++.h>



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
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(matrx[i][j] == 1) {
				ans[i]++;
			}
		}
	}
	int res = 0;
	for (auto now : ans)
	{
		if(now == 1) res++;
	}
	std::cout << res;
}