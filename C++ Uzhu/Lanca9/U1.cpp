#include <bits/stdc++.h>
#define ll long long
#define db double

void Square() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	std::cout << round(0.5*abs((x1*y2-y1*x2)+(x2*y3-y2*x3)+(x3*y4-y3*x4)+(x4*y1-y4*x1)));
}



int main() {
	Square();
}