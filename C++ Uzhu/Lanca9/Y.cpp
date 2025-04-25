#include <bits/stdc++.h>
#define ll long long
#define db double

void ah() {
	double a, b, c, a1, b1, c1;
	std::cin >> a >> b >> c >> a1 >> b1 >> c1;
	double det1 = a * b1 - b * a1;
	double det2 = a * c1 - c * a1;
	double det3 = c * b1 - b * c1;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << det3 / det1 << "\n" << det2 / det1;
}



int main() {
	ah();
}