#include <bits/stdc++.h>
#define ll long long
#define db double

void ah() {
	double x, y, x1, y1, a, b, a1, b1;
	std::cin >> x >> y >> x1 >> y1 >> a >> b >> a1 >> b1;
	std::cout << std::fixed << std::setprecision(2);
	if(x == a && y == b || x == a1 && y == b1 || x1 == a && y1 == b || x1 == a1 && y1 == b1  || x <= a1 <= x1 && y <= b1 <=y1 || x <= a <= x1 && y <= b <=y1 || x <= (a1 +a)/ 2 <= x1 && y <= (b1 + b)/2 <=y1) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}
}



int main() {
	ah();
}