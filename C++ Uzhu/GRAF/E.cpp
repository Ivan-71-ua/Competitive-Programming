#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> matrx_v(n, std::vector<int>(n));
	std::vector<int> color(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrx_v[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> color[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(matrx_v[i][j] == 1) {
				if (color[i] != color[j]) res++;
			}
		}
	}
	std::cout << res;
}