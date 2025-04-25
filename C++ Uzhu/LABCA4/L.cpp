#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int a, b, c;
	while(cin >> a >> b >> c && a !=0 && b != 0 && c != 0) {
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		if (a > b) {
			swap(a, b);
		}
		if (a * a + b * b == c * c) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
	
	
}	