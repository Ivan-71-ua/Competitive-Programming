#include <bits/stdc++.h>
#define ll long long
#define db double

void ah() {
	double s, a;
	std::cin >> s >> a;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << (-1 * a + sqrt(pow(a, 2) + 8 * s)) / 2;
}



int main() {
	ah();
}