#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fast;
    int n;
    std::cin >> n;
    std::vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> res[i];
    }
    std::stable_sort(res.begin(), res.end(), std::greater());
    int ans = res[0];
    for (int i = 1; i < n;i++)
    {
        if((i +1) % 3 != 0)
            ans += res[i];
    }
    std::cout << ans;
}