#include <bits/stdc++.h>
#define int long long


std::vector<std::vector<int>> m;

int hepl(char c, char d) {
    std::string used = "([{)]}";
    if (used.find(c) / 3 > 0 && used.find(d) / 3 < 1) return 2;
    if (used.find(c) % 3 == used.find(d) % 3 && c != d) return 0;
    return 1;
}

int HROZNY(int i, int j, std::string &s) {
    if (i > j) return 0;
    if (m[i][j] != -1) return m[i][j];

    int r = HROZNY(i + 1, j - 1, s) + hepl(s[i], s[j]);
    for (int k = i + 1; k < j; k += 2) {
        r = std::min(r, HROZNY(i, k, s) + HROZNY(k + 1, j, s));
    }

    return m[i][j] = r;
}

int32_t main() {
    std::string s;
    while (std::cin >> s) {
        m.assign(s.length(), std::vector<int>(s.length(), -1));
        int result = HROZNY(0, s.size() - 1, s);
        std::cout << result << std::endl;
    }
}
