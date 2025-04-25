#include <bits/stdc++.h>
#define ll long long

int main() {
	ll x;
	std::cin >> x;
	for (ll i = 0; i < x; i++)
	{
		std::string s;
		std::cin >> s;
		if(s.size() % 2 != 0) {
			std::cout << "NO\n";
		}
		else {
			bool ans = true;
			for (ll j = 0, l = s.size() / 2; j < s.size() / 2; j++, l++)
			{
				if(s[j] != s[l]) {
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
	
}