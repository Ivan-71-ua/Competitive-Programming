#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, k, k1;
	cin >> n;
	k = n % 10;
	k1 = n % 100;
	if (k == 1 && k1 != 11) {
		cout << n << ' ' << "bochka";
	}
	else if(k >= 2 && k <= 4 && k1 != 12 && k1 != 13 && k1 != 14) {
		cout << n << ' ' << "bochki";
	}
	else {
		cout << n << ' ' << "bochek";
	}
}