#include <bits/stdc++.h>
using namespace std;

int josephus(int n) {
   if (n == 1) {
      return 1;
   } else {
      return (josephus(n - 1) + 1) % n + 1;
   }
}

pair<int, int> josephus_sequence(int n) {
   int count = -1;
   while (true) {
      count++;
      int survivor = josephus(n);
      if (survivor == n) {
         break;
      }
      n = survivor;
   }
   return {count, n};
}

int main() {
   int t;
   cin >> t;

   for (int i = 1; i <=t; ++i) {
      int n;
      cin >> n;
      auto result = josephus_sequence(n);
		cout << "Case " << i << ": ";
      cout << result.first << " " << result.second << endl;
   }

}
