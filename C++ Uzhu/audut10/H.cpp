#include <bits/stdc++.h>
using namespace std;


long long f (long a, long n, long m) {
   if (!n)
      return 1 % m;
   if (n % 2 == 1)
      return (f (a, n - 1, m) * a) % m;
   return f ((a * a) % m, n/2, m);
}


int main() {
	long long n, l ,k;
	cin >> n >> l >> k;
	cout << f(n, l, k);
}