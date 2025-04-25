#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == b && c == d || a == c && b == d || a == d && c == b) {
		cout << a + b + c + d;
	}
	else {
		cout << "No";
	}
}