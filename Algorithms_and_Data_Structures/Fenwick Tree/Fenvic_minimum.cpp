#include <bits/stdc++.h>

using namespace std;

vector<int> a;  // Вектор для зберігання елементів
vector<int> f;  // Вектор для дерева Фенвика

// Мінімум серед елементів від 0 до x
int get_min(int x) {
	int result = INT_MAX;

	for (; x >= 0; x = (x & (x + 1)) - 1) {
		result = min(result, f[x]);
	}

	return result;
}

// Присвоєння a[idx] = val, при умові, що val <= a[idx]
void assign(int idx, int val) {
	int delta = val - a[idx];
	a[idx] = val;

	for (; idx < a.size(); idx |= idx + 1) {
		f[idx] = min(f[idx], a[idx]);
	}
}

int main() {
	int n;
	cin >> n;

	a.resize(n, 0);
	f.resize(n, INT_MAX);

	for (int i = 0; i < n; i++) {    // Ввод массива и инициализация дерева Фенвика
		int t;
		cin >> t;
		assign(i, t);
	}

	// Теперь можем обрабатывать запросы.
}
