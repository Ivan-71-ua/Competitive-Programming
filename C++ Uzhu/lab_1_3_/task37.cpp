#include <iostream>
#include <cmath>
#include<string>
#include <iomanip>
using namespace std;

int main() {
	double n, k = 1, temp = 1;
	cin >> n;
	while(k <= n) {
		double c = 1 / k;
		temp = temp * (1 + c);
		k++;
	}
	
	cout << setprecision(6) << fixed;
	cout << temp;
}