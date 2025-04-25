#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n > 0) {
		cout << 7 * (n / 7 + 1);
	}
	else {
		cout << 7 * ((n  - 7 + 1)/ 7 + 1);
	}
}