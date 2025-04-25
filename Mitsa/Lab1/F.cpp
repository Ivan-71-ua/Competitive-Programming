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
	bool res = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(!res) break;
			if(matrx[i][j] != matrx[j][i])
				res = false;
			if(i == j && matrx[i][j] == 1)
				res = false;
		}
	}
	if(res) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}