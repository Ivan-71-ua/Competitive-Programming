#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		double c;
		cin >> c;
		sum += c;
	}
	cout << fixed << setprecision(1);
	cout << sum;
}