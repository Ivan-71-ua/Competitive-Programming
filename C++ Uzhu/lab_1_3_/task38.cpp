#include <iostream>
#include <cmath>
#include<string>
#include <iomanip>
using namespace std;

int main() {
	double n, temp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double c = ((double)1 / i);
		temp = temp + c;
	}
	cout << setprecision(6) << fixed;
	cout << temp;
}