#include <bits/stdc++.h>

// Функція для DFS і пошуку мостів
void dfs(int v, int parent, std::vector<std::vector<std::pair<int, int>>> &graf,
		std::vector<int> &used, std::vector<int> &tin, std::vector<int> &fup,
		std::vector<int> &bridges, int &timer) {
	used[v] = 1; // Відзначаємо вершину як відвідану
	tin[v] = fup[v] = timer++; // Встановлюємо час входу та значення fup

	for (auto [to, idx] : graf[v]) { // Перебираємо всіх сусідів вершини v
		if (to == parent) continue; // Пропускаємо ребро до батька
		if (used[to]) {
			// Якщо сусід уже відвіданий, оновлюємо fup через зворотне ребро
			fup[v] = std::min(fup[v], tin[to]);
		} else {
			// Рекурсивно запускаємо DFS для сусіда
			dfs(to, v, graf, used, tin, fup, bridges, timer);
			// Оновлюємо fup через дочірню вершину
			fup[v] = std::min(fup[v], fup[to]);
			// Якщо умова мосту виконується, додаємо його до списку
			if (fup[to] > tin[v]) {
					bridges.push_back(idx);
			}
		}
	}
}

int main() {
	// Відкриваємо файли для зчитування та запису
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	// Створюємо граф як список суміжності
	std::vector<std::vector<std::pair<int, int>>> graf(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		graf[a].emplace_back(b, i + 1); // Додаємо ребро з індексом
		graf[b].emplace_back(a, i + 1);
	}

	// Ініціалізація змінних для DFS
	std::vector<int> used(n + 1, 0), tin(n + 1, -1), fup(n + 1, -1);
	std::vector<int> bridges; // Зберігатиме індекси мостів
	int timer = 0;

	// Запускаємо DFS для кожної компоненти графа
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i, -1, graf, used, tin, fup, bridges, timer);
		}
	}

	// Сортуємо мости за індексами
	std::sort(bridges.begin(), bridges.end());

	// Виводимо кількість мостів
	std::cout << bridges.size() << '\n';
	// Виводимо індекси мостів
	for (int bridge : bridges) {
		std::cout << bridge << '\n';
	}

	return 0;
}
