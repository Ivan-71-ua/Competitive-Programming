#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int a, b, c, temp, temp1, k, k1, k2;
	cin >> a >> b >> c;
	temp = c % 3;
	temp1 = c / 3;
	k = c * a;
	k1 = c * b;
	k2 = a * temp + temp1 * b;
	cout << min(k, min(k1, k2));
}
