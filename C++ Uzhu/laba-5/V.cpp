#include <bits/stdc++.h>
using namespace std;


int main() {
	string str;
   char ch = 'a';
   int n,k,i,j;
   cin >> n;
   for (i=0, k=n-1; i < n; i++, k--) {
      str=str+ch;
      ch++;
      cout << 'a';
      for (j=0; j<k; j++) cout << " ";
      cout << str << "\n";
   }
}