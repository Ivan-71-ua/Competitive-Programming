#include <bits/stdc++.h>
int MOD = 1;
#define int long long
int f(int n) {
	int ans = 0;
	int i =1;
	while(i <= n) {
		int v = n / i;
		int l = n / v + 1;
		ans += v * (l - i);
		i = l;
	}
	return  ans;
}


int32_t main() {
	int a,b;
	while(std::cin >> a >> b && a != 0 && b != 0) {
		std::cout << f(b) - f(a -1) << '\n';
	}
}