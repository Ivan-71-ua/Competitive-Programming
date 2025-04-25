#include <bits/stdc++.h>
using namespace std;


long long Factorial(long long n) {
	long long k = 1;
	for (long long i = 1; i <= n; i++) {
		k *= i;
	}
	return k;
}

int main() {
	long long n;
	cin >> n;
	cout << Factorial(n);
}