#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		cin >> c;
		if(c % 2 != 0) {
			cout << c << " ";
		}
	}
}