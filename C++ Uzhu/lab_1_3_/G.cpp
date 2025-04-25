#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, a, b, c, k, k1, k2, k3, k4, k5, sum;
	cin >> n;
	c = n % 10;
	n = n / 10;
	b = n % 10;
	a = n / 10;
	k = a * 100 + c * 10 + b;
	k2 = b * 100 + a * 10 + c;
	k3 = b * 100 + c * 10 + a;
	k4 = c * 100 + b * 10 + a;
	k1 = c * 100 + a * 10 + b;
	k5 = a * 100 + b * 10 + c;
	sum = k + k1 + k2 + k3 + k4 + k5;
	cout << sum;
}

