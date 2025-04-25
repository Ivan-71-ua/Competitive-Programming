#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
	ll n;
	cin >> n;

	ll result = 0;

	for (ll k = 1; k * k <= n; ) {
		ll q = n / (k * k); 
		if (q == 0) break;

		ll r = sqrt(n / q); 
		ll l = k;          

		result = (result + (r - l + 1) * q) % MOD;
		k = r + 1; 
	}

	cout << result << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
