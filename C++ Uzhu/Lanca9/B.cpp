#include <bits/stdc++.h>
using namespace std;



double geron (double a, double b, double c){
	return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

int main() {
	double a, b, c, d, f;
	cin >> a >> b >> c >> d >> f;
	cout << fixed << setprecision(4);
	cout << geron(a, b, f) + geron(c, d, f);
}