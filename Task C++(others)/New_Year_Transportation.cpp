#include <bits/stdc++.h>
#define ll long long
#define db double




int main() {
	ll n, t;
	bool ans = false;
	std::cin >> n >> t;
	ll arr_l[n] {};
	for (ll i = 1; i < n; i++)
	{
		std::cin >> arr_l[i];
	}
	for (ll i = 1; i <= n; ) {
		if(i == t) {
			ans = true;
			break;
		}
		else if(i > t) {
			break;
		}
		else {
			i += arr_l[i];
		}
	} 
	if(ans) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}