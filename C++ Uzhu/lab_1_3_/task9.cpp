#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long x;
	cin >> x;
	bool v1 = (x % 2 != 0);
	bool v2 = (x > 0 && 0 < x / 100 && x / 100 < 10);
	if (v1 || v2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
