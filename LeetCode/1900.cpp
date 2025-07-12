




#include <bits/stdc++.h>

class Solution {
	int F[31][31][31]{};
	int G[31][31][31]{};

	std::pair<int,int> dfs(int n, int f, int s) {
		if (f > s)
			std::swap(f, s);
		if (f + s > n + 1)
			return dfs(n, n + 1 - s, n + 1 - f);
		if (F[n][f][s])
			return {F[n][f][s], G[n][f][s]};
		if (f + s == n + 1) {
			F[n][f][s] = G[n][f][s] = 1;
			return {1, 1};
		}

		int earliest = INT_MAX, latest = INT_MIN;
		int nextN = (n + 1) / 2;

		if (s <= nextN) {
			for (int i = 0; i < f; i++) {
				int nf = i + 1;
				for (int j = 0; j < s - f; j++) {
					int ns = i + j + 2;
					auto res = dfs(nextN, nf, ns);
					earliest = std::min(earliest, res.first);
					latest = std::max(latest, res.second);
				}
			}
		} else {
			int sPrime = n + 1 - s;
			int midGap = (n - 2 * sPrime + 1) / 2;
			for (int i = 0; i < f; i++) {
				int nf = i + 1;
				for (int j = 0; j < sPrime - f; j++) {
					int ns = i + j + midGap + 2;
					auto res = dfs(nextN, nf, ns);
					earliest = std::min(earliest, res.first);
					latest = std::max(latest, res.second);
				}
			}
		}
		F[n][f][s] = earliest + 1;
		G[n][f][s] = latest + 1;
		return {F[n][f][s], G[n][f][s]};
	}

public:
	std::vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
		memset(F, 0, sizeof(F));
		memset(G, 0, sizeof(G));
		auto res = dfs(n, firstPlayer, secondPlayer);
		return {res.first, res.second};
	}
};
