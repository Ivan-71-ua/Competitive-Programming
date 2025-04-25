#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool IsPrime(int n) {
	int a = 0;
	for (int i = 2, squr = sqrt(n); i <=squr; i++) {
		if(n % i == 0) {
			a = i;
			break;
		}
	}
	if (a == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	if (IsPrime(n)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}