#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, temp = 1;
	cin >> n;
	for (int i = 1; i <= 5; i++) {
		int a = n % 10;
		if (i % 2 != 0) {
			temp = temp * a;
		}
		n = n / 10;
	}
	cout << abs(temp);
}
