#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, a, b, c, d, e;
	cin >> x;
	e = x % 10;
	x = x / 10;
	d = x % 10;
	x = x / 10;
	c = x % 10;
	x = x / 10;
	b = x % 10;
	a = x / 10;
	cout << a + bool(a % 2 == 0) << b + bool(b % 2 == 0) << c + bool(c % 2 == 0) <<  d + bool(d % 2 == 0) << e + bool(e % 2 == 0) ;
}
