	#include <bits/stdc++.h>
	#define ll long long




	int main() {
		ll t;
		std::cin >> t;
		for (ll i = 0; i < t; i++)
		{
			std::string k;
			std::cin >> k;
			std::cout <<  10 * ((int)(k[0]) - 49) + k.size() * (k.size() + 1) / 2 << '\n';
		}

	}