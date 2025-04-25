#include <bits/stdc++.h>
#define ll long long




int main() {
	ll n;
	std::cin >> n;
	if(n&1) {
		ll k = n / 2 - 1;
		std::cout << k + 1 << '\n';
		for (int i = 0; i < k; i++)
		{
			std::cout << "2 ";
		}
		std::cout << "3";
		} else {
			ll k = n / 2;
			std::cout << k << '\n';
			for (int i = 0; i < k; i++)
		{
			std::cout << "2 ";
		}
		}
}