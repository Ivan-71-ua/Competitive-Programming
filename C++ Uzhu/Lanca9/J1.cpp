#include <bits/stdc++.h>
#define ll long long
#define db double


void SV() {
	db d, p;
	std::cin >> d >> p;
	double a = sqrt( p*p - d * d / 4 ) ;
   double h = sqrt( p * p - d * d / 2 ) ;
   double S = d*( d + 2 * a) ;
	double V = d * d * h / 3;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << S << " " << V;
}


int main() {
	SV();
}