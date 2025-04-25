#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

struct Matrixs
{
	int x;
	int y;
	int x1;
	int y1;
};
Matrixs Ones;
Matrixs Zero;
int mood = 1000000009;

Matrixs multi(Matrixs A, Matrixs B) {
	Matrixs C;
	C.x = (A.x * B.x + A.y * B.x1) % mood;
	C.y = (A.x * B.y + A.y * B.y1) % mood;
	C.x1 = (A.x1 * B.x + A.y1 * B.x1) % mood;
	C.y1 = (A.x1 * B.y + A.y1 * B.y1) % mood;
	return C;
}
Matrixs Quick_binim(Matrixs X, int n) {
	if(n == 0) {
		return Zero;
	}
	if(n == 1) {
		return X;
	}
	Matrixs A = Quick_binim(X, n / 2);
	A = multi(A, A);
	if (n % 2 != 0) {
		A = multi(A, Ones);
	}
	return A;
}

int32_t main()
{
	Ones.x = 1, Ones.y = 1, Ones.x1 = 1, Ones.y1 = 0;
	Zero.x = 0, Zero.y = 0, Zero.x1 = 0, Zero.y1 = 0;
	int a;
	std::cin >> a;
	Matrixs T = Quick_binim(Ones, a + 1);
	int res = (T.y * T.x + mood - 1) % mood;
	std::cout << res;
}
