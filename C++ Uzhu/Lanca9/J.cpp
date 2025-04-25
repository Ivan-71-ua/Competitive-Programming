#include <bits/stdc++.h>
#define ll long long
#define db double

void Foo(ll n) {
	for (ll i = 1; i <= n; i++) {
		if (n % i == 0 && i % 2 != 0) {
			std::cout << i << "\n";
   	}
	}
}



int main() {
	ll g;
	std::cin >> g;
	Foo(g);
}