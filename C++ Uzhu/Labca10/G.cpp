#include <bits/stdc++.h>
#define ll long long


long long fuck[32]{};

long long HROZNY(int n) {
	if (n <= 1) return 1;
   if (fuck[n] != 0) return fuck[n];
   return fuck[n] = n * HROZNY(n-1);
}


int main() {
	int k;
	std::cin >> k;
	std::cout << HROZNY(k);
}
