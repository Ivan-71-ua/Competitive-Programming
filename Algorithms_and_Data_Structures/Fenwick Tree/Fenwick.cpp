#include <bits/stdc++.h>

using namespace std;

vector<int> a;  // масив
vector<int> f;  // дерево Фенвика

// Сумма елементів від 0 до x
int sum(int x) {
	int result = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) {
		result += f[x];
	}
	return result;
}

// Сумма елементів від l до r
int sum(int l, int r) {
	if (l) {
		return sum(r) - sum(l - 1);
	} else {
		return sum(r);
	}
}

// Збільшення a[idx] на delta
void increase(int idx, int delta) {
	a[idx] += delta;
	for (; idx < a.size(); idx = idx | (idx + 1)) {
		f[idx] += delta;
	}
}

int main() {
	int n;
	cin >> n;

	a.resize(n);
	f.resize(n, 0);  // Ініціалізуємо f нулями

	for (int i = 0; i < n; i++) {  // Ввод масиву та заповнення дерева Фенвика
		int t;
		cin >> t;
		increase(i, t);
	}

	for (auto now: a)
	{
		std::cout << now << ' ';
	}
	
	// Тепер можна обробляти запити
	return 0;
}
