#include <bits/stdc++.h>
#define ll long long
#define db double

ll Foo(ll n) {
	ll k = 0;
	for (ll i = 1; i <= n; i++) {
		if (n % i == 0) {
			k++;
		}
	}
	return k;
}



int main() {
	ll g;
	std::cin >> g;
	std:: cout << Foo(g);
}