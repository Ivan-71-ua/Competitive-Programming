#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
int main()
{
	fast
	int n;
	std::cin >> n;
	if (n < 4){
		std::cout << -1;
	}
	else
	{
		if (n % 2 == 0)
		{
			for (int i = n; i > 0 ; i -= 2) {
				std::cout << i << " ";
			}
			for (int i = 1; i < n; i += 2) {
				std::cout << i << " ";
			}
		}
		else
		{
			for (int i = 2; i <= n; i += 2) {
				std::cout << i << " ";
			}
			for (int i = 1; i < n - 1; i += 2) {
				std::cout << i << " ";
			}
			std::cout << n - 1;
		}
	}
}