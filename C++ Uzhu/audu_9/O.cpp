#include <bits/stdc++.h>
using namespace std;

double My_fun(double x, double y, double z) {
	return min(min(max(x,y),max(y,z)), x + y + z);
}

int main() {
	double  x, y, z;
	cin >> x >> y >> z;
	cout << My_fun(x, y, z);
}