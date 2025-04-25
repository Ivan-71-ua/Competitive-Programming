#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c, d, a1, b1, c1, d1, x, y;
	cin >> a >> b >> c >> d >> a1 >> b1 >> c1 >> d1 >> x >> y;
	
	if (a <= x && c >= x && b >= y && d <= y) {
		if (a1 <= x && c1 >= x && b1 >= y && d1 <= y) {
			cout << "SAD";
		}
		else {
			cout << "HAPPY";
		}
	}
	else {
		cout << "SAD";
	}
}