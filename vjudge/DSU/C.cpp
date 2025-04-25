#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;


int N, M;
vector<int> pos;
vector<vector<pair<int, int>>> adj;
vector<int> component;

void dfs(int node, int label, int minW) {
  if (component[node] != -1) return;
  component[node] = label;
  for (auto& edge : adj[node]) {
    if (edge.second >= minW && component[edge.first] == -1) {
      dfs(edge.first, label, minW);
    }
  }
}

bool valid(int minW) {
  component.assign(N, -1);
  int label = 0;
  for (int i = 0; i < N; i++) {
    if (component[i] == -1) {
      dfs(i, label++, minW);
    }
  }
  for (int i = 0; i < N; i++) {
    if (component[i] != component[pos[i] - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  //freopen("wormsort.in", "r", stdin);
  //freopen("wormsort.out", "w", stdout);
  
  cin >> N >> M;
  pos.resize(N);
  adj.resize(N);
  
  bool sorted = true;
  for (int i = 0; i < N; i++) {
    cin >> pos[i];
    if (pos[i] != i + 1) {
      sorted = false;
    }
  }

  if (sorted) {
    cout << -1 << endl;
    return 0;
  }


  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);

  }

  int low = 0, high = 1e9 + 1;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    if (valid(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  if (low == 0) {
    cout << -1 << endl;
  } else {
    cout << low << endl;
  }

  return 0;
}
