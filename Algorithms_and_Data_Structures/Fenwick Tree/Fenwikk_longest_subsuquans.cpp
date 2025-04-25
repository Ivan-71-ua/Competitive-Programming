#include <bits/stdc++.h>
using namespace std;

vector<int> seq;     // Вектор для зберігання вхідної послідовності
vector<int> a;       // Вектор для зберігання значень, що відповідають дереву Фенвика
vector<int> f;       // Вектор дерева Фенвика

int get_max(int x) {
	int result = INT_MIN;

	for (; x >= 0; x = (x & (x + 1)) - 1) {
		result = max(result, f[x]);
	}

	return result;
}

// Встановлюємо значення (val >= a[idx])
void assign(int idx, int val) {
	a[idx] = val;

	for (; idx < f.size(); idx |= idx + 1) {
		f[idx] = max(f[idx], val);
	}
}

int main() {
	int n;
	cin >> n;

	seq.resize(n);
	int max_val = 0;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		max_val = max(max_val, seq[i]);
	}

	// Встановлюємо розміри векторів, залежно від максимального значення в послідовності
	a.resize(max_val + 1, 0);
	f.resize(max_val + 1, INT_MIN);

	for (int x : seq) {
		int prev_max = (x > 0) ? get_max(x - 1) : 0;  // Максимальна довжина, яку можна продовжити

		if (prev_max + 1 > a[x]) {
			assign(x, prev_max + 1);
		}
	}

	int ans = get_max(max_val);
	cout << ans << endl;
}
