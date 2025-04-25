#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double numbers, part1 = 0, part2 = 0, quantity = 0, s =0;
	cout << fixed << setprecision(11);
	while (cin >> numbers && numbers != 0 ) {
		part1 += pow(numbers, 2);
		part2 += numbers;
		quantity += 1;
   }
	s = pow(((part1 - (pow(part2, 2) / quantity)) / (quantity - 1)), 0.5);
	cout << s;
}