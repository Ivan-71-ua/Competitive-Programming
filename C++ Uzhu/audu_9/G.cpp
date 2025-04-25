#include <bits/stdc++.h>
using namespace std;


double Function1(double n) {
	return pow(n, 3) + 2 * pow(n, 2) - 3;
}

int main() {
	double n;	
	while(cin >> n) {
		cout << fixed << setprecision(4)<< Function1(n);
		cout << endl;
	}
}