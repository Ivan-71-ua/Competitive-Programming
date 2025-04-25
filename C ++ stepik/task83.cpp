#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
bool IsPointInSquare( double x, double y) {
	return abs(x) <= 1 && abs(y) <= 1;
}

int main() {
	double a, b;
	cin >> a >> b;
	if (IsPointInSquare(a, b)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}