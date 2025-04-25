#include <bits/stdc++.h>



int main() {
	std::vector<int> coins(5);
	for (int i = 0; i < 5; i++) {
		std::cin >> coins[i];
	}
	
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += coins[i];
	}
	
	if (total % 5 == 0 && total != 0) {
		int b = total / 5;
		std::cout << b << '\n';
	} else {
		std::cout << "-1" << '\n';
	}
}