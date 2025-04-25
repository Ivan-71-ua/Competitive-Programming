	#include <bits/stdc++.h>
	using namespace std;
	#define int long long
	const int MAXN = 500000;

	vector<int> fenwickd(MAXN + 1, 0);
	vector<int> initsth(MAXN + 1);

	void updateFenwick(vector<int>& fenwick, int idx, int d, int n) {
		while (idx <= n) {
			fenwick[idx] += d;
			idx += (idx & -idx);
		}
	}

	int queryFenwick(const vector<int>& fenwick, int idx) {
		int sum = 0;
		while (idx > 0) {
			sum += fenwick[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	void applyRangeUpdate(int l, int r, int d, int n) {
		updateFenwick(fenwickd, l, d, n);
		updateFenwick(fenwickd, r + 1, -d, n);
	}

	int getCurrentStrength(int idx) {
		return initsth[idx] + queryFenwick(fenwickd, idx);
	}

	int32_t main() {
		std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
		int numGods, numQueries;
		cin >> numGods >> numQueries;

		for (int i = 1; i <= numGods; i++) {
			cin >> initsth[i];
		}

		for (int i = 0; i < numQueries; i++) {
			int Type;
			cin >> Type;

			if (Type == 1) {
				int l, r;
				cin >> l >> r;
				applyRangeUpdate(l, r, -1, numGods);
			} else if (Type == 2) {
				int l, r, kratosStrength;
				cin >> l >> r >> kratosStrength;
				bool Survives = true;
				for (int j = l; j <= r; j++) {
					int godStrength = max(getCurrentStrength(j), (long long)1);
					kratosStrength /= godStrength;
					if (kratosStrength == 0) {
						cout << j << endl;
						Survives = false;
						break;
					}
				}
				if (Survives) {
					cout << -1 << '\n';
				}
			}
		}
	}
