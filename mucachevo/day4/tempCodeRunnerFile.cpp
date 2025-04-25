#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 600000;

vector<int> freq(MAXN, 0);
vector<int> arr;

void solve() {
	int n, q;
	cin >> n >> q;

	arr.resize(n + 1);
	for (int i = 1; i <= n; i = i + 1) {
		cin >> arr[i];
		freq[arr[i]] = freq[arr[i]] + 1;
	}

	for (int t = 0; t < q; t = t + 1) {
		int type;
		cin >> type;

		if (type == 1) {
			int idx, x;
			cin >> idx >> x;
			freq[arr[idx]] = freq[arr[idx]] - 1;
			arr[idx] = x;
			freq[arr[idx]] = freq[arr[idx]] + 1;
		} else if (type == 2) {
			int l, r, k;
			cin >> l >> r >> k;

			bool is_divisible = true;
			for (int iteration = 0; iteration < 30; iteration = iteration + 1) {
					int pos = uniform_int_distribution<int>(l, r)(rng);
					if (freq[arr[pos]] % k != 0) {
						is_divisible = false;
						break;
					}
			}

			if (is_divisible) {
					cout << "YES\n";
			} else {
					cout << "NO\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
