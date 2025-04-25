#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<int> arr(n + 1);
		unordered_map<int, int> hash_map;
		vector<int> prefixXOR(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (hash_map.find(arr[i]) == hash_map.end()) {
					hash_map[arr[i]] = uniform_int_distribution<int>(1, INT_MAX)(rng);
			}
			arr[i] = hash_map[arr[i]];
			prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
		}

		while (q--) {
			int l, r;
			cin >> l >> r;

			int subarrayXOR = prefixXOR[r] ^ prefixXOR[l - 1];
			if (subarrayXOR == 0) {
					cout << "Yes\n";
			} else {
					cout << "No\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}
