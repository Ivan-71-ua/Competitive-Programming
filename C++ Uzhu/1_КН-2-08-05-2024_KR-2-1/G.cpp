#include <bits/stdc++.h>


long long lcm(long long a, long long b) {
    long long gcd = std::gcd(a, b);
    long long product = a * (b / gcd);
    return product;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> banderlogs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> banderlogs[i];
    }
    long long total_bananas = banderlogs[0];
    for (int i = 1; i < n; i++) {
        total_bananas = lcm(total_bananas, banderlogs[i]);
    }

    std::cout << total_bananas % k << std::endl;
    return 0;
}

