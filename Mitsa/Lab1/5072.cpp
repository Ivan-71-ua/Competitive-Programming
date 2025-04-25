#include <bits/stdc++.h>


int main() {
	int n;
	int ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			std::cin >> tmp;
			ans += tmp;
		}
	}
	std::cout << ans;
}