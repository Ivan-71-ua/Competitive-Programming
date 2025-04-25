#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> marx(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> marx[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(marx[i][j] == 1) {
				std::cout << i +1 << ' ' << j +1 << '\n';
			}
		}
		
	}
	
}