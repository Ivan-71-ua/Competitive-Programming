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
	parent[a] = b;
}


int main()
{
	fast;

	int n;

	cin >> n;

	setup(n);

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;

		if (a != 0)
		{
			unite(i, a);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int pi = getParent(i);

		if (pi == i)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << pi << "\n";
		}
	}

	return 0;
}

