
#include <bits/stdc++.h>
#define ll long long
#define db double
#define PI acos(-1.0)


void kut (double a, double b){
	db res = atan2(b,a);
   if (res < 0) res += 2*PI;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << res;
}


int main() {
	db a, b;
	std::cin >> a >> b;
	kut(a, b);
}