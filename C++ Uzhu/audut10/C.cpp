#include <bits/stdc++.h>
using namespace std;

double Quantity_of_number(int n) {
	double c;
	if(n == 0) {
		return 0;
	}
	cin >> c;
	return c + Quantity_of_number(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << fixed << setprecision(1);
	cout << Quantity_of_number(n);
	
}