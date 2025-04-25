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
	cin >> n ;
	for (int i = 0; i < n; i++) {
		double k;
		cin >> k;
		sum +=k;
		}
		cout << sum;
}