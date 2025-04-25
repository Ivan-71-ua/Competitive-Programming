#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long x;
	cin >> x;
	bool v1 = (x % 2 == 0);
	bool v2 = (x < 0 && x % 3 == 0);
	if (v1 && v2) {
		cout << "NO";
	}
	else if ( v1 || v2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
