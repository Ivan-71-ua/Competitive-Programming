#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	double max;
	cin >> n;
	cin >> max;
	for (int i = 0; i < n - 1; i++) {
		double k1;
		cin >> k1;
		if(abs(max) < abs(k1)) {
			max = k1;
		}
		
	}
	cout << fixed << setprecision(2);
	cout << abs(max);
}