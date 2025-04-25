#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	int min;
	int max;
	cin >> n;
	cin >> min;
	max = min;
	for (int i = 0; i < n - 1; i++) {
		int k1;
		cin >> k1;
		if(min > k1) {
			min = k1;
		}
		if (max < k1) {
			max = k1;
		}
	}
	cout << min + max;
}