#include <bits/stdc++.h>

int main() {
	
	int n, m;
	std::cin >> n >> m;
	while (n > 0 || m > 0) {
		if (n > 0) {
				std::cout << "B";
				n--;
		}
		if (m > 0) {
				std::cout << "G";
				m--;
		}
	}
	std::cout << std::endl;
}
