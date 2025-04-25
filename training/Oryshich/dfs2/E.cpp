#include <bits/stdc++.h>

void dfs1(int cur, std::vector<int> &used, std::vector<std::vector<int>> &graf, std::vector<int> &top) {
	used[cur] = 1;
	for (auto next : graf[cur]) {
		if (!used[next]) {
			dfs1(next, used, graf, top);
		}
	}
	top.push_back(cur);
}

void dfs2(int cur, int c, std::vector<std::vector<int>> &rgraf, std::vector<int> &color, std::vector<int> &repr) {
	color[cur] = c;
	repr[c] = cur;
	for (auto next : rgraf[cur]) {
		if (color[next] == -1) {
			dfs2(next, c, rgraf, color, repr);
		}
	}
}

int main() {
	
	freopen("firesafe.in", "r", stdin);
	 freopen("firesafe.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> graf(n + 1), rgraf(n + 1);
	std::vector<int> used(n + 1, 0), top, color(n + 1, -1), repr(n + 1, -1);

	// Зчитуємо ребра графа та будуємо його обернену версію
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		graf[a].push_back(b);
		rgraf[b].push_back(a);
	}

	// Запуск першого обходу (топологічний порядок)
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs1(i, used, graf, top);
		}
	}

	// Реверсуємо порядок для другого обходу
	std::reverse(top.begin(), top.end());
	int c = 0;

	// Запуск другого обходу (розбиття на компоненти сильної зв’язності)
	for (int v : top) {
		if (color[v] == -1) {
			dfs2(v, c++, rgraf, color, repr);
		}
	}

	// Ідентифікуємо компоненти, з яких виходять ребра
	std::vector<int> isImportant(c, 1);
	for (int i = 1; i <= n; ++i) {
		for (int to : graf[i]) {
			if (color[i] != color[to]) {
					isImportant[color[i]] = 0;
			}
		}
	}

	// Підрахунок і виведення результату
	std::vector<int> fireStations;
	for (int i = 0; i < c; ++i) {
		if (isImportant[i]) {
			fireStations.push_back(repr[i]);
		}
	}

	std::cout << fireStations.size() << '\n';
	for (int station : fireStations) {
		std::cout << station << ' ';
	}

	return 0;
}
