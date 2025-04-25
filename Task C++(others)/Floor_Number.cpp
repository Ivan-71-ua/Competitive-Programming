#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, x;
		std::cin >> n >> x;
		for (int i = 0; ; i++)
		{
			if(i * x + 2 >= n) {
				std::cout << i + 1 << '\n';
				break;
			}
		}
	}
}