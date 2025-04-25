#include <bits/stdc++.h> 

int main() {
	int n;
	std::cin >> n;
	std::vector<bool> seen(n + 1, false);
	for (int i = 0; i < n; ++i) {
		int color;
		std::cin >> color;
		seen[color] = true;
	}
	int missing = -1; 
	for (int i = 1; i <= n; ++i) {
		if (!seen[i]) {
			missing = i;
			break;
		}
	}
	if (missing != -1) {
		std::cout << missing << std::endl;
	} else {
		std::cout << -1 << std::endl;
	}
}
