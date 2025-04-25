#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, x1, y1, x2, y2, x3, y3;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	x3 = x ^ x1 ^ x2;
	y3 = y ^ y1 ^ y2;
	cout << x3 << " " << y3;
} 	