#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Power(double n, int a) {
	if (a == 0) {
		return 1;
	}
	else if (a % 2 == 0) {
		if (a ==  2) {
			return n * n;
		}
		return n * n  * Power(n, a - 2);
	}
	else if (a % 2 == 1) {
		if (a == 1) {
			return n ;
		}
		return n * Power(n, a - 1);
	}
}

int main() {
	double n;
	int a;
	cin >> n >> a;
	cout << Power(n, a);
}