	#include <bits/stdc++.h>
	#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
int cc = 0;
std::vector <int> parent;
void setup(int n)
{
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
		cc++;
		parent[a] = b;
   }
}

int main () {
	int n, m;
	std::cin >> n >> m;
	setup(n);
	for (int i = 0; i < m; i++)
	{
		int k, p;
		std::cin >> k >> p;
		unite(k, p);
		std::cout << n - cc << '\n';
	}
	
}