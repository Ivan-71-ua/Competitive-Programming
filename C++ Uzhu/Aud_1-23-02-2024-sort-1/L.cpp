#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long


int sumRegion(int row1, int col1, int row2, int col2, std::vector<std::vector<int>>& sum_p) {
    return sum_p[row2 + 1][col2 + 1] - sum_p[(row1 + 1) - 1][col2 + 1] - (sum_p[row2 + 1][(col1 + 1) - 1] - sum_p[(row1 + 1) - 1][(col1 + 1) - 1]);
}

int32_t main() {
    int t;
	 std::cin >> t;
	 while(t--) {
        int m;
        std::cin >> m;
        std::vector<std::vector<int>> tp(m, std::vector<int>(m, 0));
        std::vector<std::vector<int>> sum_p (m + 2, std::vector<int>(m + 2, 0));
        std::string st;
        while(std::cin >> st && st != "END") {
            if(st == "SET") {
                int x, y, k;
                tp[x][y] = k;
                for (int i = 0; i < m; i++)
                {
                    int sum = 0;
                    for (int j = 0; j < m; j++)
                    {
                        sum += tp[i][j];
                        sum_p[i + 1][j + 1] = sum;
                        sum_p[i + 1][j + 1] += sum_p[(i + 1) - 1][j + 1];
                    }
                }
            }
            else if (st == "SUM") {
                int x, y, x1, y1;
                std::cin >> x >> y >> x1 >> y1;
                std::cout << sumRegion(x, y, x1, y1, sum_p) << '\n';
            }
        }
    }
}

