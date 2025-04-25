#include <bits/stdc++.h>

// DFS для пошуку циклу
void dfs(const std::vector<std::vector<int>> &graf, std::vector<int> &used, std::vector<int> &path, int &flag, int cur) {
    if (flag == 1) return; // Якщо цикл знайдено
    used[cur] = 1; // Вершина в обробці
    path.push_back(cur); // Додаємо в поточний шлях
    for (int next : graf[cur]) {
        if (flag == 1) return; // Якщо цикл знайдено, припиняємо
        if (used[next] == 1) { // Знайдено цикл
            path.push_back(next);
            flag = 1;
            return;
        }
        dfs(graf, used, path, flag, next); // Рекурсивно переходимо до сусіда
    }
    used[cur] = 2; // Вершина оброблена
    path.pop_back(); // Видаляємо з поточного шляху
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m; // Зчитуємо кількість вершин і ребер

    std::vector<std::vector<int>> graf(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b; // Зчитуємо ребро
        graf[a].push_back(b); // Додаємо напрямок
    }

    std::vector<int> used(n + 1, 0), path; // used: 0 - не відвідана, 1 - обробка, 2 - завершена
    int flag = 0; // Прапор для визначення циклу

    for (int i = 1; i <= n; ++i) {
        if (flag == 1) break; // Якщо знайдено цикл
        if (used[i] == 0) dfs(graf, used, path, flag, i); // Запускаємо DFS
    }

    if (flag == 1) { // Якщо знайдено цикл
        int to = path.back(); // Кінець циклу
        int i = path.size() - 2;
        while (path[i] != to) i--; // Визначаємо початок циклу
        std::cout << "YES\n";
        for (; i < path.size() - 1; i++) {
            std::cout << path[i] << ' '; // Виводимо вершини циклу
        }
        std::cout << '\n';
    } else {
        std::cout << "NO\n"; // Циклу немає
    }

    return 0;
}
