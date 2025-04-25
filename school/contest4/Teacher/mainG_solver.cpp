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
vector <int> sz;

vector <ll> res;

void setup(int n)
{
	parent.clear();
	parent.resize(n + 1);

	sz.clear();
	sz.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		sz[i] = 1;
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
		parent[b] = a;

		sz[a] += sz[b];
	}
}


int main()
{
	fast;

	vector <pair<int, pii> > dat;
	int n, m, i, j, a, b, w;

	cin >> n >> m;
	res.resize(m + 1, 0);
	for (i = 1; i < n; i++)
	{
		cin >> a >> b >> w;
		dat.push_back({ w, {a, b} });
	}

	setup(n);

	sort(dat.begin(), dat.end());

	for (i = 0; i < n - 1; i++)
	{
		a = dat[i].second.first;
		b = dat[i].second.second;
		w = dat[i].first;

		if (getParent(a) == getParent(b))
		{
			continue;
		}

		res[w] += (ll)sz[getParent(a)] * sz[getParent(b)] * 2;

		unite(a, b);
	}
	
	for (i = 1; i <= m; i++)
	{
		cout << res[i] << "\n";
	}

	return 0;
}