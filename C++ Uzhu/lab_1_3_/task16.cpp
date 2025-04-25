#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, a, b, c, d;
	cin >> n;
	d = n / 1000;
	a = n % 10;
	n = n / 10;
	b = n % 10;
	n = n / 10;
	c = n % 10;
	cout << d * 1000 + b * 100 + c * 10 + a;
}
   a = n % 10;
	n = n / 10;
	b = n % 10;
	n = n / 10;
	c = n % 10;
	n = n / 10;
	d = n % 10;
	e = n / 10;