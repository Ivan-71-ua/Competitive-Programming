#include <bits/stdc++.h>
#define ll long long
#define db double

int vect(int x1, int y1, int x2, int y2)
{
return x1 * y2 - y1 * x2;
}


int main() {
	double xa, ya, xb, yb, xc, yc, xo, yo;
	std::cin >> xo >> yo >> xa >> ya >> xb >> yb >> xc >> yc;
	db p = vect(xa - xo, ya - yo, xb - xa, yb - ya);
	db q = vect(xb - xo, yb - yo, xc - xb, yc - yb);
	db r = vect(xc - xo, yc - yo, xa - xc, ya - yc);
	if ((p <= 0 && q <= 0 && r <= 0) || (p >= 0 && q >= 0 && r >= 0))
		std::cout << 1;
	else
		std::cout << 0;
}