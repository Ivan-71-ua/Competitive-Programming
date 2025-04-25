#include <bits/stdc++.h>
using namespace std;


long long Riz(long long n, long long m) {
	long long k = 0;
	k += abs(n - m);
	return k;
}

int main() {
	long long n, m;
	cin >> n >> m;
	cout << Riz(n, m);
}