#include <bits/stdc++.h>
#define int long long


int32_t main() {
    int n, k;
    std::cin >> n >> k;
    std::set<char> ones;
    std::set<char> second;
    for (int i = 0; i < n; i++)
    {
        char num;
        std::cin >> num;
        ones.insert(num);
    }
    for (int i = 0; i < k; i++)
    {
        char num;
        std::cin >> num;
        second.insert(num);
    }
    char tmp = '1';
    for (int i = 0; i < 9; i++)
    {
        if(ones.count(tmp) && second.count(tmp)) {
            std::cout << tmp;
            return 0;
        }
        tmp++;
    }
    if(*ones.begin() > *second.begin()) {
        std::cout << *second.begin() << *ones.begin();
    } else {
        std::cout << *ones.begin() << *second.begin();
    }
}