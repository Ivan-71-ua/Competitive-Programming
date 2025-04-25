#include <bits/stdc++.h>

// Перший DFS для знаходження топологічного порядку
void dfs1(int cur, std::vector<int> &used, std::vector<std::vector<int>> &graf, std::vector<int> &top) {
	used[cur] = 1; // Позначаємо вершину як відвідану
	for (auto next : graf[cur]) {
		if (!used[next]) { // Рекурсивно обходимо сусідні вершини
			dfs1(next, used, graf, top);
		}
	}
	top.push_back(cur); // Додаємо вершину до топологічного порядку
}

// Другий DFS для розбиття на компоненти сильної зв’язності
void dfs2(int cur, int c, std::vector<std::vector<int>> &rgraf, std::vector<int> &color ) {
	color[cur] = c; // Присвоюємо компоненту номер
	for (auto next : rgraf[cur]) {
		if (color[next] == -1) { // Рекурсивно обходимо вершини
			dfs2(next, c, rgraf, color);
		}
	}
}

int main() {
	freopen("condense2.in", "r", stdin);
	freopen("condense2.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> graf(n + 1), rgraf(n + 1);
	std::vector<int> used(n + 1, 0), top, color(n + 1, -1);
	std::set<std::pair<int, int>> edges;

	// Зчитування графа та побудова оберненого графа
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		graf[a].push_back(b); // Прямий граф
		rgraf[b].push_back(a); // Обернений граф
	}

	// Перший DFS для знаходження топологічного порядку
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs1(i, used, graf, top);
		}
	}

	// Реверсуємо порядок для другого DFS
	std::reverse(top.begin(), top.end());
	int c = 0;

	// Другий DFS для розбиття на компоненти сильної зв’язності
	for (int v : top) {
		if (color[v] == -1) {
			dfs2(v, c++, rgraf, color);
		}
	}

	// Ідентифікація унікальних ребер між компонентами сильної зв’язності
	for (int i = 1; i <= n; ++i) {
		for (int to : graf[i]) {
			if (color[i] != color[to]) { // Якщо вершини належать різним компонентам
					edges.insert({color[i], color[to]});
			}
		}
	}

	// Вивід кількості ребер між компонентами
	std::cout << edges.size();

	return 0;
}
