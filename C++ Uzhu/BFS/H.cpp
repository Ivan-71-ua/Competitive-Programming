#include <bits/stdc++.h>

void BFS(int s, std::vector<std::vector<int>> &v, std::vector<bool> &used, std::vector<int> &weight) {
    std::queue<int> qu;
    used[s] = true;
    weight[s] = 0;
    qu.push(s);
    while (!qu.empty())
    {
        int tmp = qu.front();
        qu.pop();
        for (auto now: v[tmp])
        {
            if(!used[now]) {
                qu.push(now);
                weight[now] = std::min(weight[now], 1 + weight[tmp]);
                used[now] = true;
            }
        }

    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n +1);
    std::vector<int> weight(n + 1, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        std::vector<bool> used(n + 1);
        int g;
        std::cin >> g;
        BFS(g, v, used, weight);
    }
    int ver= -1;
    int abs = -1;
    for (int i = 1; i <= n; i++) {
        if(weight[i] > abs) {
            abs = weight[i];
            ver = i;
        }
    }
    std::cout << abs << '\n' << ver;
}