#include <bits/stdc++.h>



int main() {
	int t;
	std::cin >> t;
	if(t % 10 != 0)
		std::cout << -1;
	else {
		int res = 0;

		int k = t % 500;
		res += k;
		t -= k * 500;

		k = t % 200;
		res += k;
		t -= k * 200;

		k = t % 100;
		res += k;
		t -= k * 100;

		k = t % 50;
		res += k;
		t -= k * 50;

		k = t % 20;
		res += k;
		t -= k * 20;

		k = t % 10;
		res += k;
		t -= k * 10;

		std::cout << res << '\n';
	}
}
