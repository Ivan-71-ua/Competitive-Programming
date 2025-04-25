#include <bits/stdc++.h>
#define ll long long




int main() {
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll k;
		std::cin >> k;
		ll arr_v[k];
		for (int i = 0; i < k; i++)
		{
			std::cin >> arr_v[i];
		}

		std::cout << *std::max_element(arr_v, arr_v + k) - *std::min_element(arr_v,arr_v+k) << "\n";
	}
	
}