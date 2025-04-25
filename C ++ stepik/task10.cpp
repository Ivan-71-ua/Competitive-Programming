#include <iostream>

using namespace std;

int main() {
   int a, b, c, a1, b1, c1, o, p, N;
   cin >> a >> b >> c;
	cin >> a1 >> b1 >> c1;
	o = a * 3600 + b * 60 + c;
	p = a1 * 3600 + b1 * 60 + c1;
	N = p - o;
	
   cout << N ;
}