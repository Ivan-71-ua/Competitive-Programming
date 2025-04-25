#include <bits/stdc++.h>


const int MOD1 = 1000000007, p1 = 29, MAXN = 1e5;
std::vector <int> ppow1(MAXN);

int code(char c) {
   return c - 'a' + 1;
}

int hashInterval (int l, int r, std::vector <int> &currHash) {
   return ((currHash[r] - currHash[l - 1] * ppow1[r - l + 1]) % MOD1 + MOD1) % MOD1;
}

void solve() {
   int k;
   std::cin >> k;
   std::vector <std::string> a(k);
   std::vector <std::vector <int>> hashes(k, std::vector <int>(MAXN));
   int l = 1, r = 1e4;
   std::string res = "";
   ppow1[0] = 1;
   for (int i = 0; i < r; i++) {
      ppow1[i + 1] = (ppow1[i] * p1) % MOD1;
   }
   for (int i = 0; i < k; i++) {
      std::cin >> a[i];
      r = std::min(r, (int)a[i].size());
      for (int j = 0; j < a[i].size(); j++) {
         hashes[i][j + 1] = (hashes[i][j] * p1 + code(a[i][j])) % MOD1;
      }
   }
   while (l <= r) {
      int m = (l + r) / 2;
      std::set <int> st;
      for (int i = 0; i < k; i++) {
         std::set <int> curr;
         for (int j = 0; j + m <= a[i].size(); j++) {
            curr.insert(hashInterval(j + 1, j + m, hashes[i]));
         }
         if (i) {
            std::set <int> tmp;
               for (auto &x : st) {
                  if (curr.find(x) != curr.end()) {
                     tmp.insert(x);
                  }
               }
               st = tmp;
            }
         else {
               st = curr;
            }
      } 
      if (st.empty()) r = m - 1;
      else {
         l = m + 1;
         for (int i = 0; i + m <= a[0].size(); i++) {
            if(hashInterval(i + 1, i + m, hashes[0]) == *st.begin()) {
               res = a[0].substr(i, m);
               break;
               }
         }
      }
   }
   std::cout << res << '\n';
}

int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	solve();
}