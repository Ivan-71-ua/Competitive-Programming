#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
// inclides end
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

int main()
{
	fast;
	std::vector <std::pair<int, int> > edges;
   std::vector <std::pair<int, int> > weight;
   int n, m, a, b, w;
   // start reading input
   std::cin >> n >> m;
   for (int i = 0; i < m; i++)
   {
      std::cin >> a >> b >> w;
      edges.push_back({ a, b });
      weight.push_back({ w, i });
   }
// end reading input
   std::sort(weight.begin(), weight.end());
   setup(n);
   long long sumW = 0;
   for (int i = 0; i < m; i++)
   {
      int j = weight[i].second;
      w = weight[i].first;
      a = edges[j].first;
      b = edges[j].second;
      int ap = getParent(a);
      int bp = getParent(b);
      if (ap != bp)
      {
         sumW += w;
         unite(a, b);
      }
   }
   std::cout << sumW << "\n";
   return 0;
}