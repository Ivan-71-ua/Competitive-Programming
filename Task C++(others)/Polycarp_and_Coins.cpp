#include <bits/stdc++.h>
#define ll long long



int main()
{
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll n, c, c1;
		std::cin >> n;
		c = n / 3;
		c1 = c;
		if(n % c * 3 != 0) {
			ll k = n % (c * 3);
			if(k == 1)
				c++;
			if(k == 2)
				c1++;
		}
		std::cout << c << ' ' << c1 << "\n";
	}
}