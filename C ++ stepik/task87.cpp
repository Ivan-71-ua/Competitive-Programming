#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int MinDivisor(int n) {
	int a = 0;
	for (int i = 2, squr = sqrt(n); i <=squr; i++) {
		if(n % i == 0) {
			a = i;
			break;
		}
	}
	if (a == 0) {
		return n;
	}
	else {
		return a;
	}
}

int main() {
	int n;
	cin >> n;
	cout << MinDivisor(n);
	cout << endl;
	system("pause");
}