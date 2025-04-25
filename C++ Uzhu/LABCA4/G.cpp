#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		double c1;
		cin >> c >> c1;
		if(c1 < 50) {
			k += c;
		}
	}
	cout << k;
}