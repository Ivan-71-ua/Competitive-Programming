#include <bits/stdc++.h>

const int MAX_L = 1 << 17;
int t[4 * MAX_L];
int a[MAX_L];

void built(int v, int tl, int tr, bool isOr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		built(v * 2, tl, tm, !isOr);
		built(v * 2 + 1, tm + 1, tr, !isOr);
		if (isOr) {
			t[v] = t[v * 2] | t[v * 2 + 1];
		} else {
			t[v] = t[v * 2] ^ t[v * 2 + 1];
		}
	}
}

void set_val(int v, int tl, int tr, int pos, int new_val, bool isOr) {
	if (tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			set_val(v * 2, tl, tm, pos, new_val, !isOr);
		} else {
			set_val(v * 2 + 1, tm + 1, tr, pos, new_val, !isOr);
		}
		if (isOr) {
			t[v] = t[v * 2] | t[v * 2 + 1];
		} else {
			t[v] = t[v * 2] ^ t[v * 2 + 1];
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	int size = 1 << n;

	for (int i = 1; i <= size; i++) {
		std::cin >> a[i];
	}

	built(1, 1, size, n % 2 == 1);

	for (int i = 0; i < m; i++) {
		int pos, val;
		std::cin >> pos >> val;
		set_val(1, 1, size, pos, val, n % 2 == 1);
		std::cout << t[1] << '\n';
	}
}
