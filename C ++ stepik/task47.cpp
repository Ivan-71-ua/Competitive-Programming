#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double P, X, Y, K, number, sum, cop;
	cin >> P >> X >> Y >> K;
	number = X + (double) Y / 100;
	sum = number + (number * P) / 100;
	K -= 1;
	while (  K != 0) {
	   sum = sum + (sum * P) / 100;
		K = K - 1;
	}

	cop = sum * 100 - floor(sum) * 100;
	cout << floor(sum) << " " << trunc(cop);
	
}