#include <iostream>
#define ll long long

ll P(ll x, ll y, ll n)
{
	if (!y) return 1;
	if (y & 1) return x * P(x * x % n, y / 2, n) % n;
	return P(x * x % n, y / 2, n);
}

int main() {
	int cs = 1;
	ll k, n, m, t, res;
	while (std::cin >> k >> n >> t && k != 0 && k != 0 && t != 0)
	{
		m = 1;
		for (int i = 0; i < t; i++) m *= 10;
		res = P(k % m, n, m);
		std::cout << "Case #" << cs++ << ": " << res << '\n';
	}
}