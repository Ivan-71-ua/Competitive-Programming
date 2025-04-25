#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

std::vector <int> parent;

int main()
{
	fast;
   int n;
   std::cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      std::cin >> arr[i];
   }
   std::sort(arr, arr + n);
   long long ans = 0;
   for (int i = 1; i < n; i++)
   {
      ans += arr[0] + arr[i];
   }
   std::cout << ans;
   return 0;
}