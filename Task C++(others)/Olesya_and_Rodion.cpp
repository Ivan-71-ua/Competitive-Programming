#include <bits/stdc++.h>

int main() {
	int n, t;
	std::cin >> n >> t;
	if(n == 1 && t == 10) {
		std::cout << -1;
	} else {
		std::string ans = "";
		ans += std::to_string(t);
		if(t == 10)
			n--;
		for (int i = 1; i < n; i++)
		{
			ans += "0";
		}
		std::cout << ans;
	}
}