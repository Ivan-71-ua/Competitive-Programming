
#include <bits/stdc++.h>
using namespace std; 
long long n, fib[46] {};
long long f(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (fib[n] != 0) return fib[n];
	return fib[n] = f(n-1) + f(n - 2);
}

int main() {
	while(cin >> n) {
		cout << f(n) % 10;
		cout << endl;
	}
	
}
