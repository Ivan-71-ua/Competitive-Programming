#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, k = 0;
	while(cin >> n && n != 0) {
		k += n;
	}
	cout << k;
}