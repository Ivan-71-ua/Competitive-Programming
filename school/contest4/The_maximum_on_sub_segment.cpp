#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fast;
    int n;
    std::cin >> n;
    std::vector<int> ans(n);
    std::vector<int> delte(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        ans[i] = k;
    }
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        delte[i] = k;
    }
    for (int i = 0; i < n; i++)
    {
        ans[delte[i] - 1] = -1;
        long long sum = 0;
        long long maxs = 0;
        for (int i = 0; i < n; i++)
        {
            if(i == ans.size() - 1 && ans[i] != -1) {
                sum += ans[i];
                maxs = std::max(sum, maxs);
            }
            else if(ans[i] != -1) {
                sum += ans[i];
            } else {
                maxs = std::max(sum, maxs);
                sum = 0;
           }
        }
        std::cout << maxs << '\n';
    }

}
