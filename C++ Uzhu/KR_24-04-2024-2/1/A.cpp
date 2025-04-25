#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n;
	std::cin >> n;
	while(n--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if(b * c >= a)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}