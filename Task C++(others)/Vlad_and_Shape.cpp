#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main () {
    int k;
    std::cin >> k;
    while(k--) {
        int n;
        std::cin >> n;
        int ones = 0;
        for (int i = 0; i < n * n; i++)
        {
            int tp;
            std::cin >> tp;
            if(tp ==  1)
                ones++;
        }
        if(ones == sqrt(ones) * sqrt(ones)) {
            std::cout << "SQUARE\n";
        } else {
            std::cout << "TRIANGLE\n";
        }
    }
}