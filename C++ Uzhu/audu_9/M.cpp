#include <bits/stdc++.h>
using namespace std;

void Fun(double x, double y, double h) {
	double i = (y - x) / h;
	for (int j = 0; j <= int(i); j++) {
		cout << fixed << setprecision(3) << x << " " << 3 * sin(x);
		x += h;
		cout << endl;
	}
}

int main() {
	double x, y , h;
	cin >> x >> y >> h;
	cout << fixed << setprecision(3);
	Fun(x, y, h);
}