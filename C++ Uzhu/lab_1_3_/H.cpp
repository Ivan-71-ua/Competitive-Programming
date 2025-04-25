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
	k = b * 100 + a * 10 + c;
	cout << k;
}