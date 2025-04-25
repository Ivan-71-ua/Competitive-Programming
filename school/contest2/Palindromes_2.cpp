#include <bits/stdc++.h>


void solve() {
   std::string s, t = "#";
   std::cin >> s;
    int m = s.size();
    for (int i = 0; i < m; i++) {
        t += s[i];
        t += "#";
    }
    s = t;
    int R = 0, j = 0, n = s.size();
    std::vector <int> M(n, 1);
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            M[i] = std::min(M[2 * j - i], R - i + 1);
        }
        while (i - M[i] >= 0 && i + M[i] < n && s[i - M[i]] == s[i + M[i]]) 
        {
            M[i]++;
        }
        if (i + M[i] - 1 > R) {
            R = i + M[i] - 1;
            j = i;
        }
    }
    long long res = 0;
    for (auto &x : M) res += x / 2;
   std::cout << res - m << '\n';
}

int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
   solve();
}