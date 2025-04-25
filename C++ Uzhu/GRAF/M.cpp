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
	bool res = false;
	for (int i = 0; i < n; i++)
	{
		if(matrx[i][i] == 1) {
			res = true;
			break;
		}
	}
	if(res) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}