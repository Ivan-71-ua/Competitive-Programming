#include <iostream>
#include <cmath>
#include<string>
#include <iomanip>
using namespace std;

int main() {
	double n, k = 1, temp = 0;
	cin >> n;
	while(k <= n) {
		double c = 0;
		for (int i = 1; i <= k; i++)
		{
			c = c + sin(i);
		}
		temp = temp + 1 / c;
		k++;
	}
	
	cout << setprecision(6) << fixed;
	cout << temp;
}