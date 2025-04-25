
#include <bits/stdc++.h>
using namespace std; 
long long n, fib[46] {};
long long f(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (fib[n] != 0) return fib[n];
	return fib[n] = f(n-1) + f(n - 2);
}
int64_t f1(int n)
{
	int64_t ans = ((pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5));
	return ans;
}

int main() {

	while(cin >> n) {
		if(n < 44) {
			cout << f(n) % 10;
			cout << endl;
		}
		else {
			cout << f1(n) % 10;
			cout << endl;
		}
		
	}
	
}
