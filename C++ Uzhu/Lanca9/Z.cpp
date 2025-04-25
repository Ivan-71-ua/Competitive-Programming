#include <bits/stdc++.h>
#define ll long long
#define db double

void ah() {
	double x, y, x1, y1, a;
	std::cin >> x >> y >> x1 >> y1 >> a;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << (x  + a * x1) / (1 + a) << " " << (y  + a * y1) / (1 + a);
}



int main() {
	ah();
}