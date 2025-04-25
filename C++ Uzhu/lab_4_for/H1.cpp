#include <iostream>
#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if(i % 2 != 0) {
			cout << i << " ";
		}
	}
}