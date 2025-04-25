#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = n % 10;
	if (n >= 0) {
		n = n + n - a;
	}
	else {
		if (n % 10 == 0) {
			a = -10;
		}
		n = n - a;
	}
}