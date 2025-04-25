#include <bits/stdc++.h>

void DFS(int k, std::vector<std::set<int>> &v, std::vector<bool> &used, std::vector<std::pair<int, int>> &res, std::vector<int> &way, int &cur) {
    used[k] = true;
    res[k].first = cur;
    cur++;
    way.push_back(k);
    for (auto now : v[k])
    {
        if(!used[now]) {
            DFS(now, v, used, res, way, cur);
        }
    }
    res[k].second = cur;
    cur++;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::set<int>> v(n + 1);
    std::vector<bool> used(n + 1);
    std::vector<std::pair<int, int>> res(n +1);
    std::vector<int> way;
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++)
        {
            int tp;
            std::cin >> tp;
            v[i].insert(tp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(!used[i]) {
            DFS(i, v, used, res, way, cur);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i].first << ' ' << res[i].second << '\n';
    }
}