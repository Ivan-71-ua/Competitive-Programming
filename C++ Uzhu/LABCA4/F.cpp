#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, k = 0, k1 = 0, k2 = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		cin >> c;
		if(c > 0) {
			k++;
		}
		else if(c < 0) {
			k1++;
		}
		else {
			k2++;
		}
	}
	cout << k << " " << k1 << " " << k2;
}