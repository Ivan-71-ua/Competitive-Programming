#include <bits/stdc++.h>
using namespace std;

int help(int n) {
	int res = 0;
	while(n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	std::cin >> n;
	int k = n;
	while(help(k) != n && k % n == 0) {
		k += n;
	}
	std::cout << k;
}
