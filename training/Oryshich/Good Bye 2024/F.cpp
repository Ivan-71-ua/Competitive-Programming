



#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAXN = 200001;

// Глобальні змінні для дерева
std::vector<int> graph[MAXN];
int degree[MAXN];

// Функція для обчислення ступеня вершини
inline int getDegree(int node) {
	return graph[node].size();
}

// Основна функція для розв'язання задачі
void solve() {
	int n;
	std::cin >> n;
	long long result = 0;

	// Очищуємо глобальні змінні для поточного тесту
	for (int i = 1; i <= n; ++i) {
		graph[i].clear();
		degree[i] = 0;
	}

	// Зчитуємо граф
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// Підрахунок кількості листків
	int leafCount = 0;
	for (int i = 1; i <= n; ++i) {
		if (getDegree(i) == 1) {
			++leafCount;
		}
	}

	// Додаємо всі пари (p, q), де q — листок
	result += 1LL * leafCount * (n - leafCount);

	// Підрахунок внутрішніх вершин
	int innerNodeCount = 0;
	for (int i = 1; i <= n; ++i) {
		if (getDegree(i) > 1) {
			int adjacentInnerNodes = 0;
			for (int neighbor : graph[i]) {
				if (getDegree(neighbor) > 1) {
					++adjacentInnerNodes;
				}
			}
			if (adjacentInnerNodes == getDegree(i)) {
				++innerNodeCount;
			}
			degree[i] = adjacentInnerNodes;
		}
	}

	// Обчислюємо пари для внутрішніх вершин
	for (int i = 1; i <= n; ++i) {
		if (getDegree(i) > 1 && degree[i] != getDegree(i)) {
			result += 1LL * innerNodeCount * (degree[i] - 1);
		}
	}

	// Вивід результату
	std::cout << result << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int testCases;
	std::cin >> testCases;

	while (testCases--) {
		solve();
	}

	return 0;
}
