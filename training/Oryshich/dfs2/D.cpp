#include <bits/stdc++.h>

// Функція DFS для знаходження точок артикуляції
void dfs(int v, int parent, std::vector<std::vector<int>> &graf,
		std::vector<int> &used, std::vector<int> &tin, std::vector<int> &fup,
		std::vector<int> &dot, int &timer) {
	int children = 0; // Лічильник дочірніх вершин
	used[v] = 1; // Позначаємо вершину як відвідану
	tin[v] = fup[v] = timer++; // Встановлюємо час входу та fup

	for (auto to : graf[v]) { // Перебираємо всі сусідні вершини
		if (to == parent) continue; // Пропускаємо ребро до батька
		if (used[to]) {
			// Оновлюємо fup для зворотного ребра
			fup[v] = std::min(fup[v], tin[to]);
		} else {
			// Рекурсивно викликаємо DFS для дочірньої вершини
			dfs(to, v, graf, used, tin, fup, dot, timer);
			// Оновлюємо fup через дочірню вершину
			fup[v] = std::min(fup[v], fup[to]);
			// Перевірка на точку артикуляції
			if (fup[to] >= tin[v] && parent != -1) {
					dot[v]++;
			}
			children++;
		}
	}

	// Коренева вершина є точкою артикуляції, якщо в неї більше одного дочірнього вузла
	if (parent == -1 && children > 1)
		dot[v]++;
}

int main() {
	freopen("points.in", "r", stdin); // Зчитування з файлу
	freopen("points.out", "w", stdout); // Запис у файл
	int n, m;
	std::cin >> n >> m;

	// Створення графу у вигляді списку суміжності
	std::vector<std::vector<int>> graf(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		graf[a].emplace_back(b);
		graf[b].emplace_back(a);
	}

	// Ініціалізація змінних
	std::vector<int> used(n + 1, 0), tin(n + 1, -1), fup(n + 1, -1);
	std::vector<int> dot(n + 1); // Зберігатиме точки артикуляції
	int timer = 0;

	// Запускаємо DFS для кожної компоненти графа
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i, -1, graf, used, tin, fup, dot, timer);
		}
	}

	// Вивід кількості точок артикуляції
	int size = 0;
	for (int i = 1; i <= n; i++) {
		if (dot[i]) {
			size++;
		}
	}
	std::cout << size << '\n';

	// Вивід самих точок артикуляції
	for (int i = 1; i <= n; i++) {
		if (dot[i])
			std::cout << i << '\n';
	}

	return 0;
}
