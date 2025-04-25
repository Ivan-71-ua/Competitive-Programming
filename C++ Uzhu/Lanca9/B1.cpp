#include <bits/stdc++.h>
#define ll long long
#define db double


double geron (double a, double b, double c){
	return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}


int main() {
	db x, y, z, x1, y1, z1, x2, y2, z2, x3, y3, z3;
	std::cin >> x >> y >> z >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
	db AB = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2) + pow(z1 - z, 2));
	db BC = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
	db CA = sqrt(pow(x - x2, 2) + pow(y - y2, 2) + pow(z - z2, 2));
	db AS = sqrt(pow(x3 - x, 2) + pow(y3 - y, 2) + pow(z3 - z, 2));
	db BS = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));
	db CS = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2));
	std::cout << std::fixed << std::setprecision(1);
	std::cout << geron(AB, BC, CA) + geron(AB, AS, BS) + geron(BC, BS, CS) + geron(CA, AS, CS);
}