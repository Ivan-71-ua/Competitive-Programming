#include <bits/stdc++.h>


void solve() {
    int k;
   std::cin >> k;
   std::vector <std::string> a(31);
    a[0] = "a";
    a[1] = "b";
    for (int i = 2; i <= k; i++)
        a[i] = a[i - 2] + a[i - 1];
   std::string s = a[k], t = "#";
    for (int i = 0; i < s.size(); i++) {
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
    int res = 0;
    for (auto &x : M) res += x / 2;
   std::cout << res << '\n';
}