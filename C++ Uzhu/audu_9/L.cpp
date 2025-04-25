#include <bits/stdc++.h>
using namespace std;


double Function1(double x) {
	return x + sin(x);
}		

int main() {
	double x;
	cin >> x;
	cout << fixed << setprecision(4)<< Function1(x);
}