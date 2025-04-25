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
	}
}





int main()
{
	fast;

	vector <pair<int, pii> > edges; // { {from, to}, weight }

	int n, m, a, b, w;
	cin >> n >> m;

	setup(n);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;

		edges.push_back({ w, {a, b} });
	}

	sort(edges.begin(), edges.end());

	ll mst = 0;

	for (int i = 0; i < m; i++)
	{
		if (getParent(edges[i].second.first) != getParent(edges[i].second.second))
		{
			unite(edges[i].second.first, edges[i].second.second);

			mst += edges[i].first;
		}
	}

	cout << mst << "\n";

	return 0;
}