#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double power(double a, int  b) {
	if (b > 0) {
		if(b == 1) {
		return a;
		}
		return a * power(a, b - 1);
	}
	else if (b < 0) {
		
		if(b == -1) {
		return 1 / a;
		}
		return 1 / a * power(a, b + 1);
	}
	else if (b == 0) {
		return 1;
	}
	
}

int main() {
	double a;
	int b;
	cin >> a >> b;
	cout << power(a, b);
}