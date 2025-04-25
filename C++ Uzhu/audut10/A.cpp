#include <bits/stdc++.h>
using namespace std;

int k = 0;

int Quantity_of_number(long long n) {
	if(n == 0) {
		return k++;
	}
	k++;
	return Quantity_of_number(n / 10);
}

int main() {
	long long n;
	cin >> n;
	if(n == 0) {
		cout << 1;
	}
	else {
		cout << Quantity_of_number(n);
	}
}