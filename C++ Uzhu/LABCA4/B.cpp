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
	cin >> n;
	for (int i = 0; i < n;i++) {
		double c;
		cin >> c;
		if(c > 0) {
			sum += c;
			k++;
		}
	}
	if(k == 0) {
		cout << "Not Found";
	}
	else {
		cout << fixed << setprecision(2);
		cout << sum / k;
	}
}