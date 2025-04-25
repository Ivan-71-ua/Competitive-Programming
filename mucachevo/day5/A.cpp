#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;

	ll result = 0;
	for (ll i = 1; i <= n;) {
		ll q = n / i; 
		ll r = n / q; 
		result += q * (r - i + 1); 
		i = r + 1; 
	}

	cout << result << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	return 0;
}
