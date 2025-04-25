#include <bits/stdc++.h>

void DFS(int k, std::vector<std::vector<int>> &v, std::vector<int> &used) {

    for (auto now : v[k])
    {
        used[now]++;
        DFS(now, v, used);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<int> used(n + 1);
    for (int i = 0; i < n -1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        DFS(i, v, used);
    }
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        if(used[i] == n - 1) {
            res = i;
            break;
        }
    }
    std::cout << res;
}