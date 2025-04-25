#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int32_t main() {
    int n;
    std::vector<int> dif;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string tp;
        std::cin >> tp;
        if(tp.size() < 8) {
            int k = std::stoi(tp);
            if(k > -1 && k < 1000000 + 1)
            {
                dif.push_back(k);
            }
        }
    }
    std::sort(dif.begin(), dif.end());
    if(dif[0] != 0) {
        std::cout << 0;
    } else {
        for (int i = 1; i <= dif.size(); i++)
        {
            if(i ==  dif.size())
                std::cout << dif.back() + 1;
            else if(dif[i] - dif[i-1] > 1)  {
                std::cout << dif[i - 1] + 1;
                break;
            }
        }
    }

}