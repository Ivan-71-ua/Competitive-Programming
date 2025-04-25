#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> permut(n);
        for (int i = 0; i < n; i++) {
            std::cin >> permut[i];
        }
        std::stable_sort(permut.begin(), permut.end());
        int res = 0;
        bool is = true;
        for (int i = 0; i < n; i++)
        {
            if((i +1) - permut[i] > -1) {
                res += (i + 1) - permut[i];
            } else {
                is = false;
            }
        }
        if(is) {
            std::cout << res << '\n';
        } else {
            std::cout << -1 << '\n';    
        }
    }
}
