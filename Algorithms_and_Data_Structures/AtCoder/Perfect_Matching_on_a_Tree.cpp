#include <bits/stdc++.h>

std::vector<int> DFS_Dist(std::vector<std::vector<int>> &tree, int start, int N) {
    std::vector<int> dist(N + 1);
    std::vector<bool> used(N + 1);
    std::queue<int> q;
    q.push(start);
    used[start] = true;
    dist[start] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &now: tree[v])
        {
            if(!used[now]) {
                dist[now] = dist[v] + 1;
                used[now] = true;
                q.push(now);
            }
        }
    }
    return dist;
}

std::vector<int> find_center(std::vector<std::vector<int>> &tree, int N) {
    std::vector<int> ans;
    std::vector<int> dist1 = DFS_Dist(tree, 1, N);
    int farthest = 1;
    for (int i = 1; i <= N; i++)
    {
        if(dist1[i] > dist1[farthest]) {
            farthest = i; 
        }
    }
    dist1 = DFS_Dist(tree, farthest, N);
    int otherfathest = farthest;
    for (int i = 1; i <= N; i++)
    {
        if(dist1[i] > dist1[otherfathest]) {
            otherfathest = i;
        }
    }
    std::vector<int> dist2 = DFS_Dist(tree, otherfathest, N);
    int diameter = dist1[otherfathest];
    int radius = (diameter + 1) / 2;
    for (int i = 1; i <= N; i++)
    {
        if(dist1[i] == radius && dist2[i] == diameter - radius) {
            ans.push_back(i);
        } else if(dist2[i] == radius && dist1[i] == diameter - radius) {
            ans.push_back(i);
        }
    }
    return ans;
} 

void DFS_get_sub_tree(std::vector<std::vector<int>> &tree, int N, int start, std::vector<int> &center, std::vector<int> &res) {
    std::vector<bool> used(N + 1);
    used[start] = true;
    std::queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto now: tree[v])
        {
            if(!used[now] && std::count(center.begin(), center.end(), now) == 0) {
                res.push_back(now);
                used[now] = true;
                q.push(now);
            }
        }
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> tree(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    std::vector<int> center = find_center(tree, N);
    std::vector<int> sub_ver;
    for (auto centroid: center)
    {
        for (auto child: tree[centroid])
        {
            sub_ver.push_back(child);
            DFS_get_sub_tree(tree, N, child, center, sub_ver);
        }
    }
    if(sub_ver.size() % 2 != 0)
        sub_ver.push_back(center.back());
    for (int i = 0; i < N / 2; i++)
    {
        std::cout << sub_ver[i] << ' ' << sub_ver[i + N / 2] << '\n';
    }
    return 0;
}
