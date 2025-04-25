#include <bits/stdc++.h>
#define ll long long




int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		ll k;
		std::cin >> k;
		ll arr_v[k];
		for (ll i = 0; i < k; i++)
		{
			std::cin >> arr_v[i];
		}
		std::sort(arr_v, arr_v + k);
		ll min = arr_v[k -1];
		for (ll i = 1; i < k; i++)
		{
			if(min > arr_v[i] - arr_v[i -1]) {
				min = arr_v[i] - arr_v[i - 1];
			}
		}
		std::cout << min << '\n';
	}
	
}