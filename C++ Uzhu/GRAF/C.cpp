#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> mat_ver(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> mat_ver[i][j];
		}
		
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(mat_ver[i][j] == 1)
				res++;
		}
		
	}
	std::cout << res;
}