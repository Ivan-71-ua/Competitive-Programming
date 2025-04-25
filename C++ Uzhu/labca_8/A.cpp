   #include <bits/stdc++.h>
   using namespace std;


   int main() {
      string s;
      int k = 0;
      while (cin >> s)
      {
         if(s[0] != '-') {
            k++;
         }
      }
      
      
      cout << k;
   }