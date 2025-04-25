#include <bits/stdc++.h>


std::vector<int> parent(1e5 + 10);
std::unordered_map<int, int> nums_pos;
std::vector<int> being(1e5 + 10);
std::vector<int> groups(1e5 + 10);
std::vector<int> arr_p(1e5 + 10);

int find(int x) {  
    if(parent[x] != x)
        return parent[x] = find(parent[x]);
    return x;
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        std::cin >> arr_p[i];
        parent[i] = i;
        nums_pos[arr_p[i]] = i;
        groups[i] = 3;
    }
    
    for (int i = 1; i <= n; i++) {
        if(nums_pos.count(a - arr_p[i])) {
            parent[find(nums_pos[a - arr_p[i]])] = find(i);
            being[i] |= 1;
        }
        if(nums_pos.count(b - arr_p[i])) {
            parent[find(nums_pos[b - arr_p[i]])] = find(i);
            being[i] |= 2;
        }
    }
    
    for (int i = 1; i <= n ; i++) {
        groups[find(i)] &= being[i];
    }

    for (int i = 1; i <= n ; i++) {
        if(groups[find(i)] == 0) {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";

    for (int i = 1; i <= n; i++) {
        std::cout << (groups[find(i)] & 1 ? 0 : 1) << ' ';
    }
    std::cout << '\n';

    return 0;
}