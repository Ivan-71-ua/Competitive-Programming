#include <bits/stdc++.h>
#define ll long long

long long ans[61]{};

long long HROZNY(int n) {
	if(n ==1)
		return 2;
	if (n == 2 ) {
		return 2 * 2;
	}
	if (ans[n] != 0) return ans[n];
	return ans[n] = 2 * HROZNY(n - 1);
}


int main() {
	int k;
	std::cin >> k;
	std::cout << HROZNY(k);
}
