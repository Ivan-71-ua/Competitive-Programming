#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
bool IsPointInSquare(double x, double y) {
	return   (y <= -x) && (y <= 2 * x + 2) && (pow((x + 1), 2) + pow((y-1), 2) >= 4)    ||    (y >= -x) && (y >= 2 * x + 2) && (pow((x+1), 2) + pow((y-1), 2) <= 4) ;
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