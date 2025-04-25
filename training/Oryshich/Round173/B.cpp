#include <bits/stdc++.h>


int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, d;
		std::cin>> n >> d;
		std::cout << 1;
		if (n >= 3 || d % 3 == 0)
			std::cout << " 3";
		if (d == 5)
			std::cout << " 5";
		if (d == 7 || n >= 3)
			std::cout << " 7";
		if (d == 9 || (n >= 3 && d % 3 == 0) || n >= 6)
			std::cout << " 9";
		std::cout << std::endl;
	}
	return 0;
}
