#include <bits/stdc++.h>
#define int long long
const int MAX = 5000007;

int sum(int k, const std::vector<int> &pow_k) {
    int res = 0;
    while (k) {
        res += pow_k[k % 10];
        k /= 10;
    }
    return res;
}

int g(int n, std::vector<int> &hash, const std::vector<int> &pow_k) {
    if (hash[n] > 0)
        return hash[n];
    else if (hash[n] == 0) {
        hash[n] = -1;
    }
    else if (hash[n] == -1) {
        hash[n] = n;
    }
    return hash[n] = std::min(n, g(sum(n, pow_k), hash, pow_k));
}

int calSum(int a, int b, int k, std::vector<int> &pow_k, std::vector<int> &hash) {
    for (int i = 0; i < 10; ++i) {
        pow_k[i] = pow(i, k);
    }
    long long res = 0;
    for (int p = a; p <= b; p++) {
        res += g(p, hash, pow_k);
    }
    return res;
}

int32_t main() {
    int a, b, k;
    while (std::cin >> a >> b >> k) {
        std::vector<int> pow_k(10);
        std::vector<int> hash(MAX, 0);  
        std::cout << calSum(a, b, k, pow_k, hash) << '\n';
    }
    return 0;
}
