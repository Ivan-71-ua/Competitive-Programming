#include <bits/stdc++.h>
#define ll long long




int main() {
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll a, b, c;
		std::cin >> a >> b >> c;
		if(a+b==c) {
			std::cout << "+\n";
		}
		else {
			std::cout << "-\n";
		}
	}
	
}