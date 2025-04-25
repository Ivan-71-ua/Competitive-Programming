#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double distance ( double x, double y, double x1, double y1) {
	double x2 = abs(x1 - x);
	double y2 = abs(y1 - y);
	double dis = sqrt(x2 * x2 + y2 * y2);
	return dis;
}
int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(5);
	cout << distance(a, b, c, d);
}