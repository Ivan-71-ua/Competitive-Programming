#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	int k = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		int b = n % 10;
		n = n / 10;
		if(b % 2 != 0) {
			k++;
		}
	}
	cout << k;
}