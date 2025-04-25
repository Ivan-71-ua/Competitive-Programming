#include <bits/stdc++.h>
const int MOD1 = 1000000007, MOD2 = 1000000009, p1 = 107, p2 = 113, MAXN = 2e6;
std::vector <int> ppow1(MAXN), ppow2(MAXN), hash1(MAXN), hash2(MAXN);

int code(char c) {
   return c;
}

std::pair <int, int> hashInterval (int l, int r) {
   return {
      hash1[r] - hash1[l - 1] * ppow1[r - l + 1],
      hash2[r] - hash2[l - 1] * ppow2[r - l + 1]
   };
}

void solve() {
   std::string s;
   std::cin >> s;
   int n = s.size();
   s += s;
   hash1[0] = hash2[0] = 0;
   for (int i = 1; i <= s.size(); i++) {
      hash1[i] = hash1[i - 1] * p1 + code(s[i - 1]);
      hash2[i] = hash2[i - 1] * p2 + code(s[i - 1]);
   }
   int mins = 1;
   for (int shift = 2; shift <= n; shift++) {
      int l = 0, r = n + 1;
      while (l + 1 < r) {
         int m = (l + r) / 2;
         if (hashInterval(mins, mins + m - 1) == hashInterval(shift, shift + m - 1)) l = m;
         else r = m;
      }
      if (l == n) continue;
      if (s[mins + l - 1] > s[shift + l - 1]) mins = shift;
   }
   mins--;
   std::cout << s.substr(mins, n - mins) << s.substr(0, mins) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	int t;
	std::cin >> t;
	while (t--)
	{
		solve();
	}
	
}