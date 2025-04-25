#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;

	int l1 = 0, r1 = 0;
	int l2 = INT_MAX, r2 = INT_MIN;

	int pr = 0; // Префіксна сума
	int mnl = 0, mxl = 0;
	int mnr = INT_MAX, mxr = INT_MIN;
	bool has_special = false; // Чи існує особливий елемент

	for (int i = 0; i < n; i++) {
		pr += a[i];
		if (a[i] != -1 && a[i] != 1) {
			has_special = true; // Зустріли особливий елемент
			mnr = mnl;
			mxr = mxl;
			mnl = pr;
			mxl = pr;
		}
		l1 = min(l1, pr - mxl);
		r1 = max(r1, pr - mnl);
		if (has_special) { // Оновлюємо лише якщо є особливий елемент
			l2 = min(l2, pr - mxr);
			r2 = max(r2, pr - mnr);
		}
		mnl = min(mnl, pr);
		mxl = max(mxl, pr);
	}

	vector<int> res;
	if (!has_special) {
		// Якщо немає особливого елемента, виводимо l1..r1
		for (int i = l1; i <= r1; i++) res.push_back(i);
	} else {
		// Якщо є особливий елемент, враховуємо об'єднання меж
		if (l2 > r1) {
			for (int i = l1; i <= r1; i++) res.push_back(i);
			for (int i = l2; i <= r2; i++) res.push_back(i);
		} else if (r2 < l1) {
			for (int i = l2; i <= r2; i++) res.push_back(i);
			for (int i = l1; i <= r1; i++) res.push_back(i);
		} else {
			for (int i = min(l1, l2); i <= max(r1, r2); i++) res.push_back(i);
		}
	}

	cout << res.size() << '\n';
	for (int x : res) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
