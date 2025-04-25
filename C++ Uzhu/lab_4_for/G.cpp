#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	double min;
	cin >> n;
	cin >> min;
	for (int i = 0; i < n - 1; i++) {
		double k1;
		cin >> k1;
		if(min > k1) {
			min = k1;
		}
		
	}
	cout << fixed << setprecision(2);
	cout << min * 2;
}