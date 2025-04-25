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

int cc = 0;

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

		cc--;
	}
}



int main()
{
	fast;

	int n, m, a, b;
	cin >> n >> m;

	setup(n);
	cc = n;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		unite(a, b);

		cout << cc << "\n";
	}

	return 0;
}