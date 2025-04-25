#include <bits/stdc++.h>
#define ll long long

int main() {
	ll t;
	std::cin >> t;
	for (ll j = 0; j < t; j++)
	{
		ll n, k;
		std::cin >> n >> k;
		ll x = k / (n - 1);
		ll res = k - x * (n - 1);
		if(!res) {
			std::cout << n * x - 1 << '\n';
		}
		else {
			std::cout << n * x + res << '\n';
		}
	}
}