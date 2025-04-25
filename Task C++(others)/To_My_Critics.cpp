#include <bits/stdc++.h>
#define ll long long

int main() {
	ll t;
	std::cin >> t;
	while (t--)
	{
		ll a, b, c;
		std::cin >> a >> b >> c;
		if(a + b >= 10 || a + c >= 10 || b + c >= 10) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
	
	
}