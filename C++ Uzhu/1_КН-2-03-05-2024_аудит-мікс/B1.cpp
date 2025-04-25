#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int a, b;
		std::cin >> a >> b;
		if(a == 1)
			std::cout << b / 2 << '\n';
		else {
			b /= 2;
			if(b - a <= 0)
				std::cout << 1 << '\n';
			else
				std::cout << b - a << '\n';
		}
	}
}