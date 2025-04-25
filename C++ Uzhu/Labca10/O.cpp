#include <bits/stdc++.h>
#define ll long long

ll c[10001] {};

ll HROZNY(ll n, ll m) {	
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 0; j < i; j++)
			c[i] = (c[i] + c[j] * c[i - j - 1]) % m;
		}
	return c[n];
}


int main () {
	c[0] = 1;
	ll n, m;
	std::cin >> n >> m;
	std::cout << HROZNY(n,m);
}

