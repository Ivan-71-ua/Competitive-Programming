#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, a, b, c, k, k1, k2;
	cin >> n;
	if( n > 0) {
		a = n % 10;
		n = n / 10;
		b = n % 10;
		c = n / 10;
		k = c * 10 + b;
		k1 = c * 10 + a;
		k2 = b * 10 + a;
		if (k2 < 10) {
			k2 = 100;
		}
		cout << min(k, min(k1,k2));
	}
	if( n < 0) {
		n = abs(n);
		a = n % 10;
		n = n / 10;
		b = n % 10;
		c = n / 10;
		k = (c * 10 + b) * -1;
		k1 = (c * 10 + a) * -1;
		k2 = (b * 10 + a) * -1;
		if (k2 < -10) {
			k2 = 100;
		}
		cout << min(k, min(k1,k2));
	}
}

