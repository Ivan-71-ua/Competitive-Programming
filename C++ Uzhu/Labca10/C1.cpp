#include <bits/stdc++.h>
#define ll long long

ll asses[91]{};

ll f(int n) {
	if(n == 1) {
		asses[1] = 1;
	}
	if(n == 2)
		asses[2] = 2;
	if(asses[n] != 0)
		return asses[n];
	return asses[n] = f(n - 1) + f(n - 2) + 1;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << f(n);
}