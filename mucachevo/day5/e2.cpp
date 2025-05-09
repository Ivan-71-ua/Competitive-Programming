#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e18;
const int inf = 1e9;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-8;
const long double pi = acos(-1.0);
using namespace std;

int level[MAXN], parent[MAXN], tin[MAXN], tout[MAXN], dp[MAXN];
int up[MAXN][20];
vector <int> g[MAXN];
int n, m, timer;
int ans[MAXN];
bool upper(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
void dfs_for_lcp(int v, int p){
	dp[v] = dp[p] + 1;
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i < 20; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int x : g[v])
		if (x != p) dfs_for_lcp(x, v);
	tout[v] = ++timer;
}
int lca(int a, int b){
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
	for (int i = 19; i >= 0; i--)
		if (!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}
int dfs(int v, int sz, int &center, int p = -1){
	int sum = 1;
	for (int x : g[v])
		if (level[x] == 0 && x != p)
			sum += dfs(x, sz, center, v);
	if (center == -1 && (2 * sum >= sz || p == -1))
		center = v;
	return sum;
}

void build(int v, int sz, int depth, int last){
	int center = -1;
	dfs(v, sz, center);
	level[center] = depth;
	parent[center] = last;
	for (int x : g[center])
		if (level[x] == 0)
			build(x, sz >> 1, depth + 1, center);
}
int dist(int a, int b){
	int lc = lca(a, b);
	return (dp[a] + dp[b] - 2 * dp[lc]);
}
void update(int v){
		int V = v;
		while (v != -1){
			ans[v] = min(ans[v], dist(v, V));
			v = parent[v];
		}
		return;
}
int find_ans(int v){
	int V = v;
	int res = ans[v];
	while (v != -1){
		res = min(res, ans[v] + dist(v, V));
		v = parent[v];
	}
	return res;
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y); g[y].pb(x);
	}
	dfs_for_lcp(0, 0);
	build(0, n, 1, -1);

	for (int i = 0; i < n; i++) ans[i] = inf;
	update(0);
	for (int i = 0; i < m; i++){
		int t, x;
		cin >> t >> x;
		x--;
		if (t == 1) update(x);
		else cout << find_ans(x) << " ";
	}
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
solve();
}