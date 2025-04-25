#include <iostream>

using namespace std;

int main() {
	int a, b, c, a1, b1, c1, c2;
	cin >> a >> b >> c;
	a1 = a * c;
	b1 = b * c;
	c1 = b1 % 100;
	c2 = (b1 - c1) / 100;
	cout <<a1 +c2 << " " << c1;
	return 0;
}