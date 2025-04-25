#include <iostream>

using namespace std;

int main() {
   int N, H, M, m, S, s;
   cin >> N;
   H = N / 3600 % 24;
   M = N % 3600 / 60 / 10;
   m = N % 3600 / 60 % 10;
   S = N % 3600 % 60 / 10;
   s = N % 3600 % 60 % 10;
   cout << H << ":" << M << m << ":" << S << s;
}