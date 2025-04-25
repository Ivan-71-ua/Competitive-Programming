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


vector <int> parent[2];
vector <int> sz[2];


void setup(int n)
{
	parent[0].clear();
	parent[0].resize(n + 1);
	parent[1].clear();
	parent[1].resize(n + 1);

	sz[0].clear();
	sz[0].resize(n + 1);
	sz[1].clear();
	sz[1].resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[0][i] = i;
		parent[1][i] = i;

		sz[0][i] = 1;
		sz[1][i] = 1;
	}
}

int getParent(int v, int p)
{
	if (parent[p][v] == v)
	{
		return v;
	}

	return parent[p][v] = getParent(parent[p][v], p);
}

void unite(int a, int b, int p)
{
	a = getParent(a, p);
	b = getParent(b, p);

	if (a != b)
	{
		parent[p][b] = a;

		sz[p][a] += sz[p][b];
	}
}



int main()
{
	fast;

	int n, i, j, a, b, w;
	ll sum = 0;

	cin >> n;
	setup(n);
	for (i = 1; i < n; i++)
	{
		cin >> a >> b >> w;

		unite(a, b, w);
	}

	for (i = 1; i <= n; i++)
	{
		sum += (ll)sz[0][getParent(i, 0)] * (ll)sz[1][getParent(i, 1)];
	}
	
	cout << sum - n << "\n";

	return 0;
}