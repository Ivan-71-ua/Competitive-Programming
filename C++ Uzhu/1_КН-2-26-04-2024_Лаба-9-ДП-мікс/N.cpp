#include <bits/stdc++.h>
#define MAX 1000000000

int n;
std::vector<std::vector<std::vector<char>>> m;
std::string maze;
std::vector<std::vector<std::vector<std::vector<int>>>> val;

int go(int i, int j, int k, int x) {
    if ((i >= n) || (j >= n) || (k >= n) || x < 0) return 0;
    int& temp = val[i][j][k][x];
    if (temp != -1) return temp;
    if (m[i][j][k] == '(') x++;
    if (m[i][j][k] == ')') x--;
    if ((i == n - 1) && (j == n - 1) && (k == n - 1) && (x == 0)) return 1;
    temp = 0;
    if (i < n - 1) {
        temp += go(i + 1, j, k, x);
        if (temp > MAX) temp = MAX + 1;
    }
    if (j < n - 1) {
        temp += go(i, j + 1, k, x);
        if (temp > MAX) temp = MAX + 1;
    }
    if (k < n - 1) {
        temp += go(i, j, k + 1, x);
        if (temp > MAX) temp = MAX + 1;
    }
    return temp;
}

int properPaths() {
    int ptr = 0;
    m = std::vector<std::vector<std::vector<char>>>(n, std::vector<std::vector<char>>(n, std::vector<char>(n)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                m[i][j][k] = maze[ptr++];
            }
        }
    }
    val = std::vector<std::vector<std::vector<std::vector<int>>>>(n, std::vector<std::vector<std::vector<int>>>(n, std::vector<std::vector<int>>(n, std::vector<int>(45, -1))));
    return go(0, 0, 0, 0);
}

int main() {
    while (std::cin >> n >> maze) {
        if (maze.size() != n * n * n) {
            std::cerr << "Invalid input size\n";
            continue;
        }
        int res = properPaths();
        std::cout << (res > MAX ? -1 : res) << std::endl;
    }
    return 0;
}
