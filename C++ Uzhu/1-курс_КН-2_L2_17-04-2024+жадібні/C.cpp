#include <bits/stdc++.h>



int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> date(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> date[i];
    }
    std::stable_sort(date.begin(), date.end());
    int res = 0;
    int l = 0;
    int r = date.size() - 1;
    if(date[r] > k)
        std::cout << "Impossible\n";
    else {
        while(l <= r) {
            if(date[r] + date[l] <= k) {
                l++;
            }
            r--;
            res++;
        }
        std::cout << res;
    }

}
