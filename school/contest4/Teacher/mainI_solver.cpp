#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>
#include <random>
#include <memory.h>
#include <bitset>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


vector <int> parent;
int cc;

void setup(int n)
{
	parent.clear();
	parent.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
}

int getParent(int v)
{
	if (parent[v] == v)
	{
		return v;
	}

	return parent[v] = getParent(parent[v]);
}

void unite(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a != b)
	{
		parent[a] = b;
		cc--;
	}
}



int main()
{
	fast;

	vector <pair<pii, int> > edges; // {{a, b}, 0/1}
	vector <int> qs, res;
	int n, m, q, i, j, a, b, c;

	cin >> n >> m;
	setup(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		edges.push_back({ {a, b}, 1 });
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a;

		a--;
		qs.push_back(a);

		edges[a].second = 0;
	}

	cc = n;

	for (auto it : edges)
	{
		int a = it.first.first;
		int b = it.first.second;

		int type = it.second;

		if (type == 0) { continue; }

		unite(a, b);
	}

	reverse(qs.begin(), qs.end());

	for (auto it : qs)
	{
		int a = edges[it].first.first;
		int b = edges[it].first.second;

		res.push_back(cc);

		unite(a, b);
	}

	reverse(res.begin(), res.end());

	for (auto it : res)
	{
		cout << it << " ";
	}
	cout << "\n";

	return 0;
}