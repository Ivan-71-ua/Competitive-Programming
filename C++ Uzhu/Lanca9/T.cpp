#include <bits/stdc++.h>
#define ll long long
#define db double

double Square(double x) {
	return x * x - (x * (x / 2) / 2) * 2;
}


int main() {
	double a;
	std::cin >> a;
	std::cout << Square(a);
}