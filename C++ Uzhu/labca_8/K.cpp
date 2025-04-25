#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
   char arr_kl[45] = {'1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/' };
   string s;
   while (getline(cin, s)) {
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == ' ') {
            cout << " ";
            continue;
         }
         auto x = find(begin(arr_kl), end(arr_kl), s[i]);
         int index = x - begin(arr_kl);
         cout << arr_kl[index - 1];
      }
      cout << "\n";
   }
}