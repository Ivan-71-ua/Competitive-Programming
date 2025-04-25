#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		std::string ass;
		std::cin >> ass;
		if(std::count(ass.begin(), ass.end(), 'B') > std::count(ass.begin(), ass.end(), 'A')) {
			std::cout << "B\n";
		}
		else {
			std::cout << "A\n";
		}
	}
}