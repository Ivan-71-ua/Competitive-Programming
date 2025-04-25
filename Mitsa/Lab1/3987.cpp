#include <bits/stdc++.h>



int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> matrx(n, std::vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		matrx[a - 1][b - 1] = 1;
		matrx[b - 1][a - 1] = 1;
	}
	bool res = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
		if(matrx[i][j] == 0) {
			res = false;
			break;
		}
		}
	}
	if(res) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}