
#include <bits/stdc++.h>


long long ass[51][51] {};

long long HROZNY(int x, int y)

{
   if (x <= 0 || y <= 0) return 0;
   if (ass[x][y] != 0) return ass[x][y];
   if (x <= y) return ass[x][y] = HROZNY(x-1,y-2) + HROZNY(x-2,y-1) + 2;
   return ass[x][y] = HROZNY(x-2,y-2) + 1;

}

int main() {
	int x, y;
	std::cin >> x >> y;
	std::cout << HROZNY(x, y);
}
