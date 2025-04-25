#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double P, X, Y, number, sum, cop;
	cin >> P >> X >> Y;
	number = X + (double) Y / 100;
	sum = number + (number * P) / 100;
	cop = sum * 100 - floor(sum) * 100;
	cout << floor(sum) << " " << trunc(cop);
	
}