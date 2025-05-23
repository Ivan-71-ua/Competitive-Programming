#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
bool IsPointInSquare(double x, double y) {
	return abs(x) + abs(y) <= 1;
}

int main() {
	double x, y;
	cin >> x >> y;
	if (IsPointInSquare(x, y)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}