#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300'000 + 5; 
const int Q = 300'000 + 5; 
const int T = 50; 
bitset<N + Q> randomSet[T];
unordered_map<int, int> idMap;
int idCounter = 0;
int n, q, A[N];

struct FenwickTree {
	vector<int> tree;
	FenwickTree() : tree(N, 0) {}

	void update(int idx, int value) {
		while (idx < N) {
			tree[idx] += value;
			idx += idx & -idx;
		}
	}

	int query(int idx) {
		int sum = 0;
		while (idx > 0) {
			sum += tree[idx];
			idx -= idx & -idx;
		}
		return sum;
	}
};

FenwickTree fenwick[T]; 
int getId(int x) {
	if (!idMap.count(x)) {
		idMap[x] = idCounter++;
	}
	return idMap[x];
}

void generateRandomSets() {
	mt19937 rng(228);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < N + Q; j++) {
			if (rng() & 1) randomSet[i].set(j);
		}
	}
}

void initializeFenwick() {
	for (int i = 0; i < n; i++) {
		int currentId = getId(A[i]);
		for (int j = 0; j < T; j++) {
			if (randomSet[j][currentId]) {
					fenwick[j].update(i + 1, 1);
			}
		}
	}
}

void processQueries() {
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int idx, x;
			cin >> idx >> x;
			idx--;

			int oldId = getId(A[idx]);
			int newId = getId(x);
			A[idx] = x;

			for (int j = 0; j < T; j++) {
					if (randomSet[j][oldId]) fenwick[j].update(idx + 1, -1);
					if (randomSet[j][newId]) fenwick[j].update(idx + 1, 1);
			}
		} else if (type == 2) {
			int l, r, k;
			cin >> l >> r >> k;
			l--;

			if (k == 1) {
					cout << "YES\n";
					continue;
			}
			if ((r - l) % k != 0) {
					cout << "NO\n";
					continue;
			}

			bool divisible = true;
			for (int j = 0; j < T; j++) {
				int sum = fenwick[j].query(r) - fenwick[j].query(l);
				if (sum % k != 0) {
					divisible = false;
					break;
				}
			}
			cout << (divisible ? "YES" : "NO") << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	generateRandomSets();

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	initializeFenwick();
	processQueries();

	return 0;
}
