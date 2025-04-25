#include <bits/stdc++.h>
using namespace std;


long long f (long long a, long long n) {
   if (!n)
      return 1;
   if (n & 1)
      return (f (a, n - 1) * a);
   return f ((a * a), n/2);
}


int main() {
	long long n, l;
	cin >> n >> l;
	cout << f(n, l);
}