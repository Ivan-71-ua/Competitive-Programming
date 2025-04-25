#include <iostream>
#include <cmath>
#include<string>
#include <iomanip>
using namespace std;

int main() {
	double x, n, k = 1, temp = 0;
	cin >> n >> x;
	while(k <= n) {
		temp = temp + pow(sin(x), k);
		k++;
	}
	
	cout << setprecision(6) << fixed;
	cout << temp;
}