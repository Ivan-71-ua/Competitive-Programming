#include <bits/stdc++.h>

void DFS(int k, std::vector<bool> &used, std::vector<std::set<int>> &v, std::vector<std::pair<int, int>> &res, int &cur, std::vector<int> &way) {
    used[k] = true;
    way.push_back(k);
    res[k].first = cur;
    cur++;
    for (auto now : v[k])
    {
        if(!used[now]) {
            DFS(now, used, v, res, cur, way);
        }
    }
    res[k].second = cur;
    cur++;
}



int main () {
    int n;
    std::cin >> n;
    std::vector<bool> used(n + 1);
    std::vector<std::set<int>> v(n + 1);
    std::vector<std::pair<int, int>> res(n +1);
    std::vector<int> way;
    int cur = 1;
    int a, b;
    while(std::cin >> a >> b && a != 0 && b != 0) {
        v[a].insert(b);
        v[b].insert(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if(!used[i]) {
            DFS(i, used, v, res, cur, way);
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "Vertex: " << way[i] << ", " << "Gray " << res[way[i]].first << ", " << "Black " << res[way[i]].second << std::endl;
    }

}