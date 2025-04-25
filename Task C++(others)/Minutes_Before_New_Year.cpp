#include <bits/stdc++.h>
#define ll long long

int main() {
	ll t;
	std::cin >> t;
	while (t--)
	{
		ll a, b;
		std::cin >> a >> b;
		ll h = 24 - a;
		ll m = 60 - b;
		if(m > 0)
			h--;
		std::cout << h * 60 + m << '\n';
	}
	
	
}