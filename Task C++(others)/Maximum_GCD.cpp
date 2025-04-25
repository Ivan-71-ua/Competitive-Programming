#include <bits/stdc++.h>
#define ll long long

int gcd ( int a, int b ){
	if (b == 0) return a;
	return gcd( b, a % b);
}

int main()
{
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll n;
		std::cin >> n;
		if(n % 2 == 0) {
			std::cout << n / 2 << '\n';
		}
		else {
			std::cout << (n - 1) / 2 << '\n';
		}
	}
}