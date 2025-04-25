#include <bits/stdc++.h>
#define ll long long

ll ass[47]{};

ll f(int n) {
	if(n == 0) {
		ass[0] = 1;
	}
	if(n == 1)
		ass[1] = 3;
	if(ass[n] != 0)
		return ass[n];
	return ass[n] = 3 * f(n - 1) - f(n - 2);
}

int main() {
	int n;
	std::cin >> n;
	std::cout << f(n);
}