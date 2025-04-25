

#include <bits/stdc++.h>


int main() {
	int x1, y1, z1;
	int x2, y2, z2;
	std::cin >> x1 >> y1 >> z1;
	std::cin >> x2 >> y2 >> z2;
	if ((x1 == x2 && y1 != y2 && z1 != z2) ||
		(y1 == y2 && x1 != x2 && z1 != z2) ||
		(z1 == z2 && x1 != x2 && y1 != y2)) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}
}
