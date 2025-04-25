#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, n1;
	cin >> n >> n1;
	for (int i = n; i <= n1; i++) {
		int a = i / 1000;                  
      int b = (i / 100) % 10;
      int c = (i / 10) % 10;
      int d = i % 10;
		if( (a != b) && (a != c) && (a != d) && (b != c)&& (b != d) && (c != d)) {
			cout << i << " ";
		}	
	}
}