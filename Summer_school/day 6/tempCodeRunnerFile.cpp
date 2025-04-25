#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll sum_of_mod_squares(ll n) {
	ll result = 0;
	ll sqrt_n = sqrt(n);
	
	// Пряме обчислення для малих значень i
	for (ll i = 1; i * i <= n; ++i) {
		result = (result + (n % (i * i))) % MOD;
	}
	
	// Обчислення для великих значень i
	for (ll k = 1; k * k <= n; ++k) {
		ll left = n / (k + 1) + 1;
		ll right = min(n / k, n / (k * k));
		if (left > right) continue;
		
		ll count = (right - left + 1) % MOD;
		ll sum_of_range = (count * (k * k % MOD)) % MOD;
		
		result = (result + sum_of_range) % MOD;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		cout << sum_of_mod_squares(n) << "\n";
	}

	return 0;
}
