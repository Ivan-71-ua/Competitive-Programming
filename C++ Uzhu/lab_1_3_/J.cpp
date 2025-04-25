#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, a, b, c, k;
	cin >> n;
	c = n % 10;
	n = n / 10;
	b = n % 10;
	a = n / 10;
	k = a * 100 + c * 10 + b;
	cout << k;
}