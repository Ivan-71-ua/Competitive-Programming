#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
std::vector<std::vector<int>> ans;
std::vector <int> parent;
void setup(int n)
{
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}
int getParent(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = getParent(parent[v]);
}
void unite(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
        if (ans[a].size() >= ans[b].size()) {
            for (int i = 0; i < ans[b].size(); ++i) {
                ans[a].push_back(ans[b][i]);


            }
            ans[b].clear();
            parent[b] = a;
        } else {
            for (int i = 0; i < ans[a].size(); ++i) {
                ans[b].push_back(ans[a][i]);
            }
            ans[a].clear();
            parent[a] = b;
        }
    }
}
int main()
{
    fast;
    int n;
    std::cin >> n;
    setup(n);
    ans.resize(n+1);
    for (int i = 1; i <= n ; ++i) {
        ans[i].push_back(i);
    }
    for (int i = 0; i < n-1; ++i) {
        int k, p;
        std::cin >> k >> p;
        unite(k, p);
    }

    for (int i = 1; i < ans.size(); ++i) {
       if(!ans[i].empty()) {
           for (int j = 0; j < ans[i].size();j++) {
               std::cout << ans[i][j] << " ";
           }
       }
    }
    return 0;
}