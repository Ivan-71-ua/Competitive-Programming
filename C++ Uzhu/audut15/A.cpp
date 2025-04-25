#include <bits/stdc++.h>

double way(double x, double a, int f, int p) {
	return sqrt(x * x + (1 - a) * (1 - a)) / p + sqrt(a * a + (1 - x) * (1 - x)) / f;
}

int main() {
	int p, f;
	double a;
	std::cin >> p >> f >> a;
	double L = 0;
	double R = 1;
	double ep = 1e-10; 
	while (R - L > ep)
	{
		double k = L + (R - L) / 3;
		double t = R - (R - L) / 3;
		if (way(k, a, f, p) < way(t, a, f, p))
				R = t;
		else
				L = k;
	}
	std::cout << std::fixed << std::setprecision(9) << L; 
}
