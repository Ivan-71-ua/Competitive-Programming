#include <bits/stdc++.h>
#define ll long long

int main() {
	int n, m, x;
	std::cin >> n >> m;
	int s[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			s[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			std::cin >> x;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
		
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			std::cout << s[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	
}