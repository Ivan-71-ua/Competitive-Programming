#include <bits/stdc++.h>


int main()
{
    std::string num;
    std::cin >> num;
    long long res = 0;
    for (auto& ch : num)
    {
        res += ch - '0';
    }
    if (res % 3) {
        std::cout << "no";
    }
    else {
        std::cout << "yes";
    }
}