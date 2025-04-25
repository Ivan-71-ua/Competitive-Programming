#include <bits/stdc++.h>
#define ll long long

ll all[1001][1001][1001] {};

ll F(ll a, ll b, ll c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (all[a][b][c] != 0) return all[a][b][c];
	if (a > 20 || b > 20 || c > 20)
		return all[a][b][c] = F(20, 20, 20);
	if (a < b && b < c)
		return all[a][b][c] = F(a, b, c - 1) + F(a, b - 1, c - 1) - F(a, b - 1, c);
	return all[a][b][c] = F(a - 1, b, c) + F(a - 1, b - 1, c) + F(a - 1, b, c - 1) - F(a - 1, b - 1, c - 1);
}

int main() {
   std::cout << F(10, 4, 6) << std::endl;
}
