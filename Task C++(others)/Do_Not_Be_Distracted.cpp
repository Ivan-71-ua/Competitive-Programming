#include <bits/stdc++.h>
#define ll long long




int main() {
	ll t;
	std::cin >> t;
	for (ll i = 0; i < t; i++)
	{
		ll k;
		std::cin >> k;
		std::string s, s1 = "";
		std::cin >> s;
		s1 += s[0];
		bool ans = true;
		for (ll p = 1; p < k; p++)
		{
			if(s[p -1] != s[p]) {
				s1 += s[p];
			}
		}
		for (ll l = 0; l < s1.size(); l++)
		{
			ll j = count(s1.begin(), s1.end(), s1[l]);
			if(j > 1) {
				ans = false;
				break;
			}
		}
		if(ans) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
	
}