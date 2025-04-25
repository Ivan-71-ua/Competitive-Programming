#include <bits/stdc++.h>


int n;
long long rM[31] {}, nM[31] {};
long long nonrep(int n);
long long rep(int n)
{
   if (n == 1) return 0;
   if (n == 2) return 3;
   if (rM[n] != 0) return rM[n];
   return rM[n] = rep(n - 1) + nonrep(n - 1);
}

long long nonrep(int n)
{
   if (n == 1) return 3;
   if (n == 2) return 6;
   if (nM[n] != 0) return nM[n];
   return nM[n] = 2 * rep(n - 1) + nonrep(n - 1);
}

int main()
{
   
   while(std::cin >> n)
      std::cout << rep(n) + nonrep(n) << '\n';
}