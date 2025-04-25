#include <bits/stdc++.h>
#define ll long long
#define db double




int main() {
	ll n, t;
	std::cin >> n >> t;
	ll sum = 0;
	ll arr_v[n];
	for (ll i = 0; i < n; i++)
	{
		std::cin >> arr_v[i];
		sum += arr_v[i];
	}
	if(t >= sum) {
		std::cout << n;
	}
	else {
		ll k = 0, sum1 = 0, j = 0;
		for (ll i = 0; i < n; i++)
		{
			sum1 += arr_v[i];
			if(sum1 <= t) {
				k++;
			}
			else {
				sum1 -= arr_v[j];
				j++;
			}
		}
		std::cout << k;	
	}
}