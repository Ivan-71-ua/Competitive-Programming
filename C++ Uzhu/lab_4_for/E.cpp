#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, k = 0;
	double sum = 0;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		double k1;
		cin >> k1;
		if(k1 < 0) {
			sum += k1;
			k++;
		}
	}
	cout << fixed << setprecision(2);
	cout << k << " " << sum;
}