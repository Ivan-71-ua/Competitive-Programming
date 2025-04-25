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
vector <ll> p_sum;

vector <ll> dat;
vector <int> perm;

multiset <ll> sums;

void setup(int n)
{
	parent.clear();
	parent.resize(n + 1);

	p_sum.clear();
	p_sum.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = -1;
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
		sums.erase(sums.find(p_sum[a]));
		sums.erase(sums.find(p_sum[b]));

		p_sum[b] += p_sum[a];
		sums.insert(p_sum[b]);

		parent[a] = b;
	}
}


void merge(int v)
{
	parent[v] = v;
	p_sum[v] = dat[v];
	sums.insert(dat[v]);

	if (v > 1)
	{
		if (parent[v - 1] != -1)
		{
			unite(v, v - 1);
		}
	}
	if (v + 1 < dat.size())
	{
		if (parent[v + 1] != -1)
		{
			unite(v, v + 1);
		}
	}
}


int main()
{
	fast;

	int n, i, j, a, b, c;
	
	cin >> n;

	dat.resize(n + 1);
	perm.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> dat[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> perm[i];
	}
	setup(n);

	vector <ll> res;
	res.push_back(0);

	reverse(perm.begin() + 1, perm.end());

	for (int i = 1; i < n; i++)
	{
		merge(perm[i]);
		
		res.push_back(*sums.rbegin());
	}

	reverse(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\n";
	}

	return 0;
}