#include <bits/stdc++.h>
using namespace std;


long long Factorial(long long n) {
	if(n == 1) {
		return 1;
	}
	return n * Factorial(n -1);
}

int main() {
	long long n;
	cin >> n;
	cout << Factorial(n);
}