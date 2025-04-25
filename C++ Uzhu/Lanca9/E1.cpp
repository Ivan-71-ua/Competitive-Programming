#include<bits/stdc++.h>
using namespace std;

void Foo(long long n) {
	for (int i = 2; i <= sqrt(n); i++) {
      while (n % i == 0) {
         cout << i;
         n /= i;
         if (n > 1) {
            cout << '*';
         }
      }
   }
   if (n > 1) {
      cout << n;
   }
}

int main() {
	int n;
	cin >> n;
	Foo(n);
}