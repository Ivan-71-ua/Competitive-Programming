#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c, x, y;
	
	cin >> a >> b >> c >> x >> y;
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
	if (a <= x && b <= y || a <= y && b <= x) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}