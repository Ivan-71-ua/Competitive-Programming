#include <bits/stdc++.h>
#define ll long long
#define db double

double geron (double a, double b, double c){
	return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}



int main() {
	db x, y, z;
	std::cin >> x >> y >> z;
	db sq = geron(x, y, z);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << 2 / x * sq << " " << 2 / y * sq  << " " << 2 / z * sq;
}