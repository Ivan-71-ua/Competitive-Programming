#include <iostream>

using namespace std;

int main() {
	int number, n1, n2, n3, n4, n11, n22, n33, n44, a, b, c;
	cin >> number;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	n4 = 0;
	n11 = n1 + number / 1000;
	n22 = n2 + (number % 1000 - number % 100) / 100;
	n33 = n3 + (number % 100 - number % 10) / 10;
	n44 = n4 + number % 10;
	a = (n11 - n44) * (n11 - n44);
	b = (n22 - n33) * (n22 - n33);
	c = a + b + 1;
	cout << c;
} 