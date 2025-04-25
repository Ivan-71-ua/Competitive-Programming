#include <iostream>
#define ll long long

int j(int n, int k) {
   if (n == 1)
      return 1;
   return (j(n - 1, k) + k - 1) % n + 1;
}


int main() {
	ll n, k;
	std::cin >> n >> k;
	std::cout << j(n, k);
}