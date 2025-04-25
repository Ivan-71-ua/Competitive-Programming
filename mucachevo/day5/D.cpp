#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int block_size = sqrt(n) + 1;

	vector<ll> block_sum(block_size, 0);

	for (int i = 0; i < n; i++) {
		block_sum[i / block_size] += arr[i];
	}

	while (m--) {
		int type;
		cin >> type;

		if (type == 1) { 
			int l, r;
			cin >> l >> r;
			--l, --r; 

			ll result = 0;

			int start_block = l / block_size;
			int end_block = r / block_size;

			if (start_block == end_block) {
				for (int i = l; i <= r; i++) {
					result += arr[i];
				}
			} else {
				for (int i = l; i < (start_block + 1) * block_size; i++) {
					result += arr[i];
				}

				for (int i = start_block + 1; i < end_block; i++) {
					result += block_sum[i];
				}

				for (int i = end_block * block_size; i <= r; i++) {
					result += arr[i];
				}
			}

			cout << result << '\n';

		} else if (type == 2) { 
			int i, d;
			cin >> i >> d;
			--i; 

			int block_idx = i / block_size;
			block_sum[block_idx] += d; 
			arr[i] += d;              
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
