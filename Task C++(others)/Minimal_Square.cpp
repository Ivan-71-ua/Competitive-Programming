#include <bits/stdc++.h>
#define ll long long




int main() {
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll a, b;
		std::cin >> a >> b;
		std::cout << pow((std::min(std::max(2 * b, a), std::max(2 * a, b))), 2) << '\n';	
	}
	
}