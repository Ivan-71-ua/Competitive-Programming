
#include <bits/stdc++.h>

const int MAXN = 1e5 + 5;
std::vector<long long> t(4 * MAXN); // Дерево відрізків для сум
std::vector<long long> lazy(4 * MAXN); // Лінування для відкладених оновлень

// Будуємо дерево відрізків
void build(std::vector<int>& arr, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = arr[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(arr, v*2, tl, tm);
		build(arr, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

// Функція для лінування (поширення відкладених оновлень)
void push(int v, int tl, int tr) {
	if (lazy[v] != 0) {
		t[v] += lazy[v] * (tr - tl + 1); // Оновлюємо суму у вузлі
		if (tl != tr) { // Якщо це не лист
			lazy[v*2] += lazy[v]; // Поширюємо оновлення на ліву і праву частини
			lazy[v*2+1] += lazy[v];
		}
		lazy[v] = 0; // Скидаємо лінування для поточного вузла
	}
}

// Оновлення інтервалу [l, r], додаємо значення add
void update(int v, int tl, int tr, int l, int r, int add) {
	push(v, tl, tr); // Спочатку розповсюджуємо відкладені оновлення
	if (l > r) return;
	if (l == tl && r == tr) {
		lazy[v] += add;
		push(v, tl, tr); // Виконуємо оновлення поточного інтервалу
	} else {
		int tm = (tl + tr) / 2;
		update(v*2, tl, tm, l, std::min(r, tm), add);
		update(v*2+1, tm+1, tr, std::max(l, tm+1), r, add);
		t[v] = t[v*2] + t[v*2+1]; // Оновлюємо значення вузла
	}
}

// Запит суми на інтервалі [l, r]
long long sum(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr); // Спочатку розповсюджуємо відкладені оновлення
	if (l > r) return 0;
	if (l == tl && r == tr) {
		return t[v]; // Якщо інтервал повністю покриває
	}
	int tm = (tl + tr) / 2;
	return sum(v*2, tl, tm, l, std::min(r, tm)) +
		sum(v*2+1, tm+1, tr, std::max(l, tm+1), r);
}

int main() {
	int n; // Кількість елементів
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i]; // Введення масиву
	}

	build(arr, 1, 0, n-1); // Будуємо дерево відрізків

	while (true) {
		int type;
		std::cin >> type; // 1 - сума, 2 - оновлення, 3 - вихід

		if (type == 1) { // Запит суми
			int l, r;
			std::cin >> l >> r;
			std::cout << sum(1, 0, n-1, l-1, r-1) << std::endl; // Вивести суму на інтервалі [l, r]
		} else if (type == 2) { // Оновлення інтервалу
			int l, r, x;
			std::cin >> l >> r >> x;
			update(1, 0, n-1, l-1, r-1, x); // Додати x до кожного елемента на інтервалі [l, r]
		} else if (type == 3) { // Вихід
			break;
		}
	}

	return 0;
}
