#include <bits/stdc++.h>
#define ll long long
#define db double


void SV() {
	db x, y, x1, y1, x2, y2, x3, y3;
	std::cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << (x2 + x) / 2 << " " << (y2 + y) / 2 << "\n";
	std::cout << sqrt(pow(x2 - x, 2) + pow(y2 - y, 2)) << " " << sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
}


int main() {
	SV();
}