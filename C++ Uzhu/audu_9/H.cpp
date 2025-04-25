#include <bits/stdc++.h>
using namespace std;


double Function1(double n) {
	return sqrt(n) + 2 * n + sin(n);
}		

int main() {
	double n;	
	while(cin >> n) {
		cout << fixed << setprecision(4)<< Function1(n);
		cout << endl;
	}
}