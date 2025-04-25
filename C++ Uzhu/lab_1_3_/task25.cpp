#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	n = abs(n);
	while(n != 0) {
		int k;
		k = n % 10;
		n = n / 10;
		sum = sum + k;
	}
	cout << sum;
}