#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

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
      parent[a] = b;
   }
}

int main () {
	int n;
	std::cin >> n;
	setup(n);
	for (int i = 1; i <= n; i++)
	{
		int k;
		std::cin >> k;
        if(k != 0)
            unite(i, k);

	}
    for (int i = 1; i <= n; i++)
    {
        int p = getParent(i);
        parent[i] = p;

    }
	for (int i = 1; i <= n; i++)
	{
        if(parent[i] == i) std::cout << 0 << '\n';
        else std::cout << parent[i] << '\n';
	}

}