


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000;

vector<int> fenwick1(MAXN + 1, 0);
vector<int> fenwick2(MAXN + 1, 0);
vector<int> s(MAXN + 1);

// Оновлення дерева Фенвіка
void update(vector<int>& fenwick, int idx, int delta, int n) {
	while (idx <= n) {
		fenwick[idx] += delta;
		idx += (idx & -idx);
	}
}

// Запит суми в дереві Фенвіка
int query(const vector<int>& fenwick, int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += fenwick[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

// Оновлення діапазону (від l до r) на delta
void range_update(int l, int r, int delta, int n) {
	update(fenwick1, l, delta, n);
	update(fenwick1, r + 1, -delta, n);
}

// Запит поточного значення для конкретного елемента (з урахуванням всіх змін)
int get_value(int idx) {
	return s[idx] + query(fenwick1, idx);
}

int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int l, r;
			cin >> l >> r;
			range_update(l, r, -1, n);
		} else if (type == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			bool survived = true;
			for (int j = l; j <= r; j++) {
					int current_power = max(get_value(j), 1); // отримуємо поточну силу бога
					x /= current_power;
					if (x == 0) {
						cout << j << endl;
						survived = false;
						break;
					}
			}
			if (survived) {
					cout << -1 << endl;
			}
		}
	}

	return 0;
}
