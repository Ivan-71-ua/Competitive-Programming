#include <bits/stdc++.h>

int n, m;
std::queue<std::pair<int, int>> way;
void BFS(std::vector<std::vector<int>> &graf, int d) {
    while (!way.empty())
    {
        std::queue<std::pair<int, int>> cur;
        while (!way.empty())
        {
            int x = way.front().first;
            int y = way.front().second;
            way.pop();
            if(graf[x][y] == -1) {
                graf[x][y] = d;
                if(x - 1 > -1)
                    cur.push({x - 1, y});
                if(x + 1 < n)
                    cur.push({x + 1, y});
                if(y -1 > -1)
                    cur.push({x, y - 1});
                if(y +1 < m)
                    cur.push({x, y + 1});
            }
        }
        way = cur;
        d++;
    }
}

int main() {
    int k;
    std::cin >> k;
    for (int p = 0; p < k; p++)
    {
        std::cin >> n >> m;
        std::vector<std::string> tmp_map(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> tmp_map[i];
        }
        std::vector<std::vector<int>> matrx_graf(n, std::vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(tmp_map[i][j] == '1') {
                    way.push({i, j});
                }
            }
        }
        BFS(matrx_graf, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << matrx_graf[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
}