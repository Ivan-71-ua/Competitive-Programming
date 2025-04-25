#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
	if (a + b > c) {
		cout << a + b + c;
	}
	else {
		cout << "No";
	}
}
