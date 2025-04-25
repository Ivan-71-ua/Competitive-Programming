#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

const int MAX_N = 100005;

std::vector<int> graph[MAX_N];
std::vector<int> component_sizes;
std::bitset<MAX_N> visited;

void dfs(int node, int &size) {
    visited[node] = true;
    size++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, size);
        }
    }
}

int main() {
    fast
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, size);
            component_sizes.push_back(size);
        }
    }
    std::bitset<MAX_N> possible_scores;
    possible_scores[0] = true;
    
    for (int size : component_sizes) {
        possible_scores |= (possible_scores << size);
    }
    
    std::cout << possible_scores.count() << '\n';
    return 0;
}
