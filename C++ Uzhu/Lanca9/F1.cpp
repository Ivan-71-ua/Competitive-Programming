#include <iostream> 
using namespace std;

long long fac(long long k) {
	long long n = 5, s = 0;
	while(k >= n){
      s = s + (k / n); 
      n *= 5;
   }
	return s;
}

int main() {
	int n;
	cin >> n;
	cout << fac(n);
}