#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a > 0) {
		cout << 1;
	}
	else if (a < 0 && b > 0 ) {
		cout << 0;
	}
	else if (b < 0) {
		if ((b - a) % 2 == 0) {
			cout << -1;
		}
		else {
			cout << 1;
		}
	}
	else if( a == 0) {
		cout << 0;
	}
}