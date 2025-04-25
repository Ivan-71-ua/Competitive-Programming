#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define ll long long

int main() {
	ll k;
	std::cin >> k;
	std::vector<ll> XOR(k + 1);
	XOR[0] = 0;
	for (ll i = 1; i <= k; i++)
	{
		std::cin >> XOR[i];
		XOR[i] = XOR[i] ^ XOR[i - 1];
	}
	ll m;
	std::cin >> m;
	for (ll i = 0; i < m; i++)
	{
		ll l, r;
		std::cin >> l >> r;
		std::cout << (XOR[r] ^ XOR[l - 1]) << '\n';
	}
}