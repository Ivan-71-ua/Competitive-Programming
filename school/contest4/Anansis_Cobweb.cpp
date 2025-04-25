#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
int cc = 0;
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
    if (a != b)
    {
        cc++;
        parent[a] = b;
    }
}


int main() {
    int n, m;
    std::cin >> n >> m;
    setup(n);
    std::unordered_map<int, std::pair<int, int>> all_thread;
    for (int i = 1; i <= m; i++)
    {
        int k, p;
        std::cin >> k >> p;
        all_thread[i] = {k, p};
    }
    int q;
    std::vector<int> need_del;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int tp;
        std::cin >> tp;
        need_del.push_back(tp);
    }

    for (auto now: all_thread)
    {
        if(std::find(need_del.begin(), need_del.end(), now.first) == need_del.end()) {
            unite(now.second.first, now.second.second);
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < q; i++) {
        ans.push_back( n - cc);
        unite(all_thread[need_del[i]].first, all_thread[need_del[i]].second);
    }
    for (int i = ans.size() -1; i >= 0; i--)
    {
        std::cout << ans[i] << " ";
    }

}