#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const ll BASE1 = 257, BASE2 = 359;
const int MAXN = 5005;

ll pow_base1[MAXN], pow_base2[MAXN];

void precompute_powers() {
	pow_base1[0] = pow_base2[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		pow_base1[i] = (pow_base1[i - 1] * BASE1) % MOD1;
		pow_base2[i] = (pow_base2[i - 1] * BASE2) % MOD2;
	}
}

void solve() {
	int t;
	cin >> t;

	while (t--) {
		map<pair<int, int>, int> edge_map;
		map<pair<ll, ll>, int> hash_count[MAXN];

		int n;
		cin >> n;

		vector<int> edge_ids(n);
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			if (!edge_map.count({u, v})) {
				edge_map[{u, v}] = edge_map.size();
			}
			edge_ids[i] = edge_map[{u, v}];
		}

		ll total_pairs = 0;
		for (int s = 0; s < n; s++) {
			ll hash1 = 0, hash2 = 0;
			for (int d = s; d < n; d++) {
					hash1 = (hash1 + pow_base1[edge_ids[d]]) % MOD1;
					hash2 = (hash2 + pow_base2[edge_ids[d]]) % MOD2;
					total_pairs += hash_count[d - s][{hash1, hash2}];
					hash_count[d - s][{hash1, hash2}]++;
			}
		}

		cout << total_pairs << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	precompute_powers();
	solve();

	return 0;
}
