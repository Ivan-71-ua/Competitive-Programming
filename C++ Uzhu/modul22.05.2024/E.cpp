

#include <bits/stdc++.h>


int main() {
	int x1, y1, z1;
	int x2, y2, z2;
	std::cin >> x1 >> y1 >> z1;
	std::cin >> x2 >> y2 >> z2;
	if ((x1 == 0 && x2 == 0) || (x1 == 1 && x2 == 1) || 
		(y1 == 0 && y2 == 0) || (y1 == 1 && y2 == 1) || 
		(z1 == 0 && z2 == 0) || (z1 == 1 && z2 == 1)) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}

}

