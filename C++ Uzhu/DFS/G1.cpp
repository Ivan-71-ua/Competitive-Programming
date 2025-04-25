#include <bits/stdc++.h>

void DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, int &b) {
    used[k] = true;
    if(used[b]) return;
    for (auto now: v[k])
    {
        if(!used[now]) {
            DFS(now, v, used,b);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        std::cin >> a;
        if(a != 0) {
            v[a].push_back(i);
        }
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::vector<bool> used(n + 1);
        std::cin >> a >> b;
        DFS(a, v, used, b);
        if(used[b]) {
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }

}