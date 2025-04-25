#include <bits/stdc++.h>
#define ll long long


main(){
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll n, k;
		std::cin >> n >> k;
		ll arr_a[n], arr_b[n];
		for (ll j = 0; j < n; j++)
		{
			std::cin >> arr_a[j];
		}
		for (ll l = 0; l < n; l++)
		{
			std::cin >> arr_b[l];
		}
		
		std::sort(arr_a, arr_a + n);
		std::sort(arr_b, arr_b + n, std::greater());
		for (ll p = 0; p < k; p++)
		{
			if(arr_a[p] < arr_b[p]) {
				arr_a[p] = arr_b[p];
			}
			else {
				break;
			}
		}
		ll sum = 0;
		for (ll u = 0; u < n; u++)
		{
			sum += arr_a[u];
		}
		std::cout << sum << '\n';
	}
	

}