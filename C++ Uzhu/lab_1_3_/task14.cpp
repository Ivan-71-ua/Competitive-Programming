#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long x, a, b;
	cin >> x;
	b = x % 10;
	if (x >= 0) {
		a = 10 - b;
		cout << x + a;
	}
	else {
		if (b != 0) {
			cout << x - b;
		}
		else {
			cout << x + 10;
		}
	}
}
