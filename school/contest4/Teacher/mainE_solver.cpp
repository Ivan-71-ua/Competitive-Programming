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
vector <vector <int> > segments;


void setup(int n)
{
	parent.clear();
	parent.resize(n + 1);
	segments.clear();
	segments.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		segments[i].push_back(i);
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
		if (segments[a].size() > segments[b].size())
		{
			for (auto i : segments[b])
			{
				segments[a].push_back(i);
			}
			parent[b] = a;
		}
		else
		{
			for (auto i : segments[a])
			{
				segments[b].push_back(i);
			}
			parent[a] = b;
		}
	}
}


int main()
{
	fast;

	int n, i, j, a, b, c;

	cin >> n;

	setup(n);

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;

		unite(a, b);
	}

	int sp = getParent(1);

	for (int i = 0; i < segments[sp].size(); i++)
	{
		cout << segments[sp][i] << " ";
	}
	cout << "\n";

	return 0;
}