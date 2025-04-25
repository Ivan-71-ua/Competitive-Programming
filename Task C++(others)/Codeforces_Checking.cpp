#include <bits/stdc++.h>
#define ll long long
#define db double




int main() {
	ll t;
	std::cin >> t;
	const std::string st = "codeforces";
	for (ll i = 0; i < t; i++)
	{
		std::string now;
		std::cin >> now;
		if(st.find(now) != -1) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
	
}