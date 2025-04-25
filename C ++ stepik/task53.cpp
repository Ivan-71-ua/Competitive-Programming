#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	double a, b, c, d, e, f, delta, X1, X2;
	cin >> a >> b >> c >> d >> e >> f;
	delta = (a * d) - (b * c);
	X1 = ((e * d) - (f * b)) / delta;
	X2 = ((f * a) - (e * c)) / delta;
	cout << fixed << X1 << " " << X2;
}