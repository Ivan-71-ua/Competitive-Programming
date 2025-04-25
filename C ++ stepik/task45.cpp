#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double A, B, C, square, p;
	cin >> A >> B >> C;
	p = (A + B + C) / 2;
	square = pow((p * (p - A) * (p - B) * (p - C)), 0.5);
	cout << round(square);
}