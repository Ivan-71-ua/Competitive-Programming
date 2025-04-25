#include <bits/stdc++.h>
using namespace std;


double Function1(double x, double y) {
	return x * x + sin(x * y) - y * y;
}		

int main() {
	double x, y;	
	while(cin >> x >> y) {
		cout << fixed << setprecision(4)<< Function1(x, y);
		cout << endl;
	}
}