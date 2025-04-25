#include <iostream>

using namespace std;

int main() {
   int a, b, c, d, c1, d1;
   cin >> a;
   b= a % 10;
	c = a % 100;
	d = a % 1000;
	c1 = (c - b) / 10;
	d1 = (d - c) / 100;
	cout << b + c1 + d1;
   return 0;
}