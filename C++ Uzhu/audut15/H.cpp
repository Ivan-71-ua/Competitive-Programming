#include <bits/stdc++.h>

double a, b, c, d;
const double ep = 1e-12;

double res(double x) {
   return a * x * x * x + b * x * x + c * x + d;
}

int main() {
	std::cin >> a >> b >> c >> d;
	double r = 1;
	while (res(r) * res(-r) >= 0) {
		r *= 2;
	}
	double l = -r;
	while (r - l > ep) {
		double x = (l + r) / 2;
		if (res(x) * res(r) > 0) {
				r = x;
		} else {
				l = x;
		}
	}
	std::cout << std::fixed << std::setprecision(10) << l;
}
