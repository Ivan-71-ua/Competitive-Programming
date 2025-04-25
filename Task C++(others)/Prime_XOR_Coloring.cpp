#include <bits/stdc++.h>


int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;
		if(n == 1) {
			std::cout << "1\n";
			std::cout << "1\n";
		} else if(n == 2) {
			std::cout << "2\n";
			std::cout << "1 2\n";
		} else if(n == 3) {
			std::cout << "2\n";
			std::cout << "1 2 2\n";
		} else if(n == 4) {
			std::cout << "3\n";
			std::cout << "1 2 2 3\n";
		} else if(n == 5) {
			std::cout << "3\n";
			std::cout << "1 2 2 3 3\n";
		} else {
			std::cout << "4\n";
			for (int i = 1; i <= n; i++)
			{
				std::cout << i % 4 + 1 << ' ';
			}
			std::cout << '\n';	
		}
	}
	return 0;
}
