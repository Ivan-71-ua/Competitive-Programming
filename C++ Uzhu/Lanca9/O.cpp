#include <bits/stdc++.h>
#define ll long long
#define db double

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}



int main() {
	ll k;	
	std::cin >> k;
	while (k--) {
		ll p, sum = 0;
		std::cin >> p;
		ll arr[p];
		for (int i = 0; i < p; i++)
		{
			std::cin >> arr[i];
		}
		for (ll i = 0; i < p -1 ;i++) {
			for (ll j = i + 1; j < p; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		std::cout << sum << "\n";
	}
	
}