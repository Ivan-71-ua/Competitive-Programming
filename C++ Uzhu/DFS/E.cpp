#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> res(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> res[i][j];
		}
	}
	bool is = true;
	//std::vector<bool> used(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(res[i][j] == 1) {
				if(i - 1 > -1 && res[i-1][j] == 1) {
					is = false;
					break;
				} 
			}
		}
	}
	if(is) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}