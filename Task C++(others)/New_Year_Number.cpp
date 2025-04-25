#include <bits/stdc++.h>
#define ll long long
#define db double

int main() {
	int t;
	std::cin >> t;
	while (t--)
	{
		ll k;
		std::cin >> k;
		if(k < 2020) {
			std::cout << "NO\n";
		}
		else if(k % 2020 == 0) {
			std::cout << "YES\n";
		}
		else if(k % 2021 == 0) {
			std::cout << "YES\n";
		}
		else {
			ll os = k % 2020;
			ll poc = k - os * 2021;
			if((k - poc) > 0 && (k - poc) % 2020 == 0)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
	
}