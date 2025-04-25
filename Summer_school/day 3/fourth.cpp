#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


const int N = 200'447;
const int LOG = 20;

std::vector<int> graph[N];
int tin[N];
int tout[N];
int up[N][LOG];
int T;
int depth[N];
std::vector<long long> treeK, treeB, lazyK, lazyB;
int treeSize;

void dfs(int node, int parent, int dep)
{
	tin[node] = T++;
	up[node][0] = parent;
	for (int i = 1; i < LOG; i++)
		up[node][i] = up[up[node][i - 1]][i - 1];
	depth[node] = dep;
	for (int neighbor : graph[node])
		if (neighbor != parent)
			dfs(neighbor, node, dep + 1);
	tout[node] = T++;
}

bool is_ancestor(int parent, int node)
{
	return tin[parent] <= tin[node] && tout[node] <= tout[parent];
}

int lca(int u, int v)
{
	if (is_ancestor(v, u)) return v;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (!is_ancestor(up[v][i], u))
			v = up[v][i];
	}
	return up[v][0];
}

void push(std::vector<long long> &tree, std::vector<long long> &lazy, int v, int tl, int tr)
{
	if (lazy[v] != 0)
	{
		tree[v] += lazy[v] * (tr - tl + 1);
		if (tl != tr)
		{
			lazy[v * 2] += lazy[v];
			lazy[v * 2 + 1] += lazy[v];
		}
		lazy[v] = 0;
	}
}

void update_tree(std::vector<long long> &tree, std::vector<long long> &lazy, int v, int tl, int tr, int l, int r, long long addend)
{
	push(tree, lazy, v, tl, tr);
	if (l > r)
		return;
	if (l == tl && r == tr)
	{
		lazy[v] += addend;
		push(tree, lazy, v, tl, tr);
	}
	else
	{
		int tm = (tl + tr) / 2;
		update_tree(tree, lazy, v * 2, tl, tm, l, std::min(r, tm), addend);
		update_tree(tree, lazy, v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, addend);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

long long query_tree(std::vector<long long> &tree, std::vector<long long> &lazy, int v, int tl, int tr, int l, int r)
{
	push(tree, lazy, v, tl, tr);
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return tree[v];
	int tm = (tl + tr) / 2;
	return query_tree(tree, lazy, v * 2, tl, tm, l, std::min(r, tm)) + query_tree(tree, lazy, v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
}

void update(int v, long long val)
{
	update_tree(treeB, lazyB, 1, 0, treeSize - 1, tin[v], tin[v], (depth[v] + 1) * val);
	update_tree(treeK, lazyK, 1, 0, treeSize - 1, tin[v], tin[v], -val);
}

int main()
{
	fast
	int n, q;
	std::cin >> n;
	std::vector<int> values(n);
	for (int i = 0; i < n; i++)
		std::cin >> values[i];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0, 0);
	treeSize = T;
	treeK.assign(4 * treeSize, 0);
	treeB.assign(4 * treeSize, 0);
	lazyK.assign(4 * treeSize, 0);
	lazyB.assign(4 * treeSize, 0);
	for (int v = 0; v < n; v++)
		update_tree(treeB, lazyB, 1, 0, treeSize - 1, tin[v], tin[v], values[v]);
	std::cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int t;
		std::cin >> t;
		if (t == 2)
		{
			int v;
			std::cin >> v;
			v--;
			long long k = query_tree(treeK, lazyK, 1, 0, treeSize - 1, tin[v], tout[v]);
			long long b = query_tree(treeB, lazyB, 1, 0, treeSize - 1, tin[v], tout[v]);
			std::cout << k * depth[v] + b << "\n";
		}
		else
		{
			int a, b;
			long long diff;
			std::cin >> a >> b >> diff;
			a--, b--;
			int c = lca(a, b);
			update(a, diff);
			update(b, diff);
			update(c, -2 * diff);
			update_tree(treeB, lazyB, 1, 0, treeSize - 1, tin[c], tin[c], diff);
		}
	}
	return 0;
}
