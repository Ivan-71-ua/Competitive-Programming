#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int n, k = 0;
	cin >> n;
	while (n--){
		double x;
		cin >> x;
		if (x < 30.0) k++;
	}
	int p = 2 * k / 9;
	if ((2 * k) % 9 != 0) p++;
	cout << p << " " << k;
}