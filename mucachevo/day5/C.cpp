#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
	ll n;
	cin >> n;

	ll result = 0;
	for (ll k = 1; k <= n;) {
		ll q = n / k;
		ll r = n / q; 
		ll count = (r - k + 1) % MOD;

		result = (result + (q * count) % MOD) % MOD;
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
