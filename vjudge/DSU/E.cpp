#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NMAX 500
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int grid[NMAX][NMAX];
bool visited[NMAX][NMAX];

int dfs(int i, int j, int d) {
    if (visited[i][j]) {
        return 0;
    }
    visited[i][j] = true;
    int count = 1;
    for (int dir = 0; dir < 4; dir++) {
        int i1 = i + dx[dir];
        int j1 = j + dy[dir];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n &&
            abs(grid[i1][j1] - grid[i][j]) <= d && !visited[i1][j1]) {
            count += dfs(i1, j1, d);
        }
    }
    return count;
}

bool is_possible(int d) {
    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, d) * 2 >= n * n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    //freopen("tractor.in", "r", stdin);
    //freopen("tractor.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int lo = 0, hi = 1000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (is_possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
    return 0;
}
