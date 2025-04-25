#include <bits/stdc++.h>

void DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, std::vector<int> &way) {
    used[k] = true;
    for (auto now: v[k])
    {
        if(!used[now]) {
            way[now] = k;
            DFS(now, v, used, way);
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<bool> used(n + 1);
    std::vector<int> way(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        std::cin >> a;
        v[a].push_back(i);
    }
    DFS(1, v, used, way);
    std::vector<int> ans;
    ans.push_back(n);
    int p = n;
    while(n != 1) {
        ans.push_back(way[n]);
        n = way[n];
    }
    for (int i = ans.size() - 1; i >=0; i--) {
        std::cout << ans[i] << ' ';
    }
}