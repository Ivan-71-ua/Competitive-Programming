#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	long long n, sum = 0, k = 0;
	cin >> n;
	while(n != 0) {
		long long c;
		c = n % 10;
		n = n / 10;
		if (c % 2 == 0) {
			sum += c;
			k++;
		}
	}
	if (k == 0) {
		cout << -1;
	}
	else {
		cout << sum;
	}
}