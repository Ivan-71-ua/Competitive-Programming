#include <iostream>
#include <cmath>
#include<string>
#include <iomanip>
using namespace std;

int main() {
	int n;
	long long temp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long c = pow(i, 3);
		temp = temp + c;
	}
	cout << temp;
}