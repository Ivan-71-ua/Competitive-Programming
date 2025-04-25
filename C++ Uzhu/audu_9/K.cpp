#include <bits/stdc++.h>
using namespace std;


long long Function1(long long x, long long y, long long z) {
	return x * y * z + x + y * y + z * z * z;	
}		

int main() {
	long long x, y, z;
	cin >> x >> y >> z;
	cout << Function1(x, y, z);
}