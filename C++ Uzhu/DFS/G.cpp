#include <bits/stdc++.h>

void DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, int &cur, std::vector<std::pair<int, int>> &par) {
    used[k] = true;
    par[k].first = cur;
    cur++;
    for (auto now: v[k])
    {
        if(!used[now]) {
            DFS(now, v, used, cur, par);
        }
    }
    par[k].second = cur;
    cur++;
}

int main() {
    int n;
    std::cin >> n;
    int cur = 1;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<bool> used(n + 1);
    std::vector<std::pair<int, int>> par(n + 1);
    int root;
    for (int i = 1; i <= n; i++)
    {
        int a;
        std::cin >> a;
        if(a != 0) {
            v[a].push_back(i);
        } else {
            root = i;
        }
    }
    int m;
    std::cin >> m;
    DFS(root, v, used, cur, par);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if(par[a].first < par[b].first && par[a].second > par[b].second) {
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }

}