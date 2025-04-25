#include <bits/stdc++.h>
#define ll long long
#define db double

void ah() {
	double x, y, x1, y1, x2, y2;
	std::cin >> x >> y >> x1 >>y1 >> x2 >> y2;
	double AB = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
	double BC = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double CA = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
	std::cout << std::fixed << std::setprecision(4);
	std::cout << AB + BC + CA << "\n";
	std::cout << sqrt(((AB + BC + CA) / 2) * (((AB + BC + CA) / 2) - AB) * (((AB + BC + CA) / 2) - BC) * (((AB + BC + CA) / 2) - CA));
}



int main() {
	ah();
}