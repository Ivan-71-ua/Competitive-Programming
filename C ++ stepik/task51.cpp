#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//ax2 + bx + c = 0 
int main() {
	double a, b, c, D, X1, X2;
	cin >> a >> b >> c;
	D = pow(b, 2) - 4 * a * c;
	if (D < 0) {
		return 0;
	}
	else if (D == 0 ) {
		X1 = -b / 2 * a;
		cout << fixed << X1;
		return 0;
	}
	else {
		X1 = (-b - sqrt(D)) / (2 * a);
		X2 = (-b + sqrt(D)) / (2 * a);
		if ( X1 > X2) {
			cout << fixed << X2 << " " << X1;
			return 0;
		}
		else{
			cout << fixed << X1 << " " << X2;
			return 0;
		}
	}
}
	
