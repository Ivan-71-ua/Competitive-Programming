#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graf, std::vector<bool> &used, std::vector<int> &in, std::vector<int> &out, int &time, int cur) {
    in[cur] = time++; // Час входу в вершину
    used[cur] = true; 
    for (auto next : graf[cur]) {
        if (!used[next]) {
            dfs(graf, used, in, out, time, next);
        }
    }
    out[cur] = time++; // Час виходу з вершини
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("ancestor.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graf(n);
    std::vector<bool> used(n);
    std::vector<int> in(n), out(n);
    int root = -1;

    for (int i = 0; i < n; ++i) {
        int p;
        std::cin >> p;
        if (p == 0) {
            root = i; // Знаходимо корінь дерева
        } else {
            graf[p - 1].push_back(i); // Додаємо ребро
        }
    }

    int m;
    std::cin >> m;

    int time = 0;
    dfs(graf, used, in, out, time, root); // DFS для обчислення in та out

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b; // Переходимо до нуль-індексації
        // Перевіряємо, чи є a предком b
        if (in[a] <= in[b] && out[a] >= out[b]) {
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }

    return 0;
}
