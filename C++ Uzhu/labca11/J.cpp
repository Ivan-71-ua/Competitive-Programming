#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int N;
std::vector<std::vector<int>> more;
std::vector<std::vector<int>> lessV;
std::vector<std::vector<int>> cows;

void find() {
  for (int v = 0; v < N; v++)
  {
    for (int i = 0; i < N; i++)
    {
      more[v][i + 1] = more[v][i] + ((cows[i][1] > cows[v][1]) ? 1 : 0);
      lessV[v][i + 1] = lessV[v][i] + ((cows[i][1] < cows[v][1]) ? 1 : 0);
    }
  }
}

int32_t main() {
  fast;
  std::cin >> N;
  cows.resize(N, std::vector<int>(2));
  more.resize(N, std::vector<int>(N + 1));
  lessV.resize(N, std::vector<int>(N + 1));

  for (int i = 0; i < N; i++)
  {
    std::cin >> cows[i][0] >> cows[i][1];
  }
  std::sort(cows.begin(), cows.end());
  find();
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i +1; j < N; j++)
    {
      ans++;
      int a, b;
      if(cows[j][1] > cows[i][1]) {
        b = more[j][j + 1] - more[j][i + 1];
        a = lessV[i][j + 1] - lessV[i][i + 1];
      } else {
        b = more[i][j + 1] - more[i][i + 1];
        a = lessV[j][j + 1] - lessV[j][i + 1];
      }
      ans += a + (a * b) + b;
    }
  }
  std::cout << ans + N + 1;
}


/*
#define ll long long
#define f first
#define s second
#define pii std::pair<int, int>
const int MX = 3e3;
int n;
int grid[MX][MX];

bool y(pii p1, pii p2) {
  return p1.s < p2.s;
}

ll prefSum(int x1, int y1, int x2, int y2) {
  return (ll)(grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1]);
}


int main()
{
  std::cin >> n;
  pii points[n];
  for (int i = 0; i < n; i++)
  {
    int a, b;
    std::cin >> a >> b;
    points[i] = {a, b};
  }
  std::sort(points, points + n);
  for (int i = 1; i <= n; i++)
  {
    points[i-1].f = i;
  }
  std::sort(points, points + n, y);
  for (int i = 1; i <= n; i++)
  {
    points[i-1].s = i;
  }
  for (int i = 0; i < n; i++)
  {
    grid[points[i].f][points[i].s] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n;j++) {
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
    }
  }
  ll ans = n + 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i +1; j < n; j++)
    {
      pii p1 = {points[i].f, points[i].s};
      pii p2 = {points[j].f, points[j].s};
      ans += prefSum(std::min(p1.f, p2.f), 1, std::max(p1.f, p2.f), std::min(p1.s, p2.s)) * prefSum(std::min(p1.f, p2.f), std::max(p1.s, p2.s), std::max(p1.f, p2.f), n);
    }
  }
  std::cout << ans;
}
*/
