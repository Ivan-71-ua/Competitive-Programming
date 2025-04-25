#include <bits/stdc++.h>
using namespace std;

long long gcd ( long long a, long long b ){
	if (b == 0) return a;
   return gcd( b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	int max_v = max(a, b);
	max_v = 6 - (max_v - 1);
	cout << max_v / gcd(max_v, 6) << "/" << 6 / gcd(max_v, 6);
}