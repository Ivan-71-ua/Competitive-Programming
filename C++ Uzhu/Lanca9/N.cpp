#include <bits/stdc++.h>
#define ll long long
#define db double

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}


int main() {
	ll k;	
	std::cin >> k;
	while (k--) {
		ll p, a, b = 1;
		std::cin >> p;
		while (p--) {
			std::cin >> a;
			b = lcm(b, a);
		}
		std::cout << b << '\n';
	}
	
}