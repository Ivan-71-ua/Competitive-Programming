#include <bits/stdc++.h>
using namespace std;



long long gcd ( long long a, long long b ){
	if (b == 0) return a;
   return gcd( b, a % b);
}

int main() {
	long long n, k;
	cin >> n >> k;
	cout << n * k / gcd(n, k);
}