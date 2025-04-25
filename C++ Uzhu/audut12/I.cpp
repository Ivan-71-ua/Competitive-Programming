#include <bits/stdc++.h>


void HROZNY() {
	int x, y, x1, y1, x2, y2;
	std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	int minX = std::min(x2, x1);
	int minY = std::min(y2, y1);
	int maxX = std::max(x2, x1);
	int maxY = std::max(y2, y1);
	if(minX <= x && x <= maxX && minY <= y && y <= maxY) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}
}


int main() {
	HROZNY();
}