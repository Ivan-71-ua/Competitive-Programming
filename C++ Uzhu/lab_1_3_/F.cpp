#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if ( a % 2 == 0 && b % 2 == 0 || abs(a) % 2 == 1 && abs(b) % 2 == 1) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

