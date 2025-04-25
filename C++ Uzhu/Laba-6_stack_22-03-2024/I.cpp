#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> blok(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> blok[i];
    }
    std::stack<std::pair<int ,int>> biger;
    std::vector<int> res(n, -1);
    biger.push({blok[0], 0});
    for (int i = 1; i < n; i++)
    {
        while(!biger.empty()) {
            if(biger.top().first >= blok[i])
                break;
            else {
                res[biger.top().second] = blok[i];
                biger.pop();
            }
        }
        biger.push({blok[i], i});
    }
    for (auto now : res)
    {
        std::cout << now << ' ';
    }

}