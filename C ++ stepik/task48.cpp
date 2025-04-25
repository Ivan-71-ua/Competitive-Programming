#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double numbers, sum, quantity = 1;
	cin >> numbers;
	cout << fixed << setprecision(11);
	sum = numbers;
	while (cin >> numbers && numbers != 0 ) {
		sum += numbers;
		quantity += 1;
	}
	cout << sum / quantity;
}