#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

std::unordered_map<int, int> cont;

std::set<int> PrimeFactors(int n) {
    std::set<int> r;
    for (int i = 2; i * i <= n; i += 1 + (i > 2)) {
        while (n % i == 0) {
            r.insert(i);
            cont[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        r.insert(n);
        cont[n]++;
    }
    return r;
}

int main() {
    fast
    int n;
    while (std::cin >> n) {
        cont.clear();
        std::set<int> res = PrimeFactors(n);
        bool first = true;
        std::string ans;
        for (auto now : res) {
            if (!first) {
                ans += "*";
            }
            ans += std::to_string(now);
            if (cont[now] > 1) {
                ans += "^" + std::to_string(cont[now]);
            }
            first = false;
        }
        std::cout << ans << '\n';
    }
    
    return 0;
}
