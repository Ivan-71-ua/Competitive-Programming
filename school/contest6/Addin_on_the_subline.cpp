#include <bits/stdc++.h>
#define int long long

int value[500004];
int tree[500004];
int mode[500004];
void build_tree(int v, int tl, int tr) {
   if (tl == tr) {
      tree[v] = value[tl];
   } else {
      int tm = (tl + tr) / 2;
      build_tree(v * 2, tl, tm);
      build_tree(v * 2 + 1, tm + 1, tr);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
   }
}


void push(int v, int tl, int tr) {
   if (mode[v] != 0 && v * 2 + 1 < 500004) {
      mode[v * 2] += mode[v];
      mode[v * 2 + 1] += mode[v];
      int tm = (tl + tr) / 2;
      tree[v * 2] += (tm - tl + 1) * mode[v];
      tree[v * 2 + 1] += (tr - tm) * mode[v];
      mode[v] = 0;
   }
}


int get_sum(int l, int r, int v, int tl, int tr) {
   if (l <= tl && tr <= r) {
      return tree[v];
   }
   if (tr < l || r < tl) {
      return 0;
   }
   push(v, tl, tr);
   int tm = (tl + tr) / 2;
   return get_sum(l, r, v * 2,     tl,    tm) + get_sum(l, r, v * 2 + 1, tm + 1, tr);
}


void add(int l, int r, int val, int v, int tl, int tr) {
   if (l <= tl && tr <= r) {
      tree[v] += val * (tr - tl + 1);
      mode[v] += val;
      return;
   }

   if (tr < l || r < tl) {
      return;
   }

   push(v, tl, tr);
   int tm = (tl + tr) / 2;
   add(l, r, val, v * 2,     tl,     tm);
   add(l, r, val, v * 2 + 1, tm + 1, tr);
   tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int main() {
   int n;
   std::cin >> n;
   for (int i = 0; i < n; i++)
   {
      std::cin >> value[i];
   }
   int q;
   build_tree(1, 0, n - 1);
   std::cin >> q;

   while (q--)
   {
      char ask;
      std::cin >> ask;
      if(ask == '?') {
         int k, p;
         std::cin >> k >> p;
         std::cout << get_sum(k - 1, p - 1, 1, 0, n - 1) << '\n';
      } else {
         int k, p, ad;
         std::cin >> k >> p >> ad;
         add(k - 1, p - 1, ad, 1, 0, n - 1);
      }
   }
}