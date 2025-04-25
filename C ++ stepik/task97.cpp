#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	string s;
	int quantity = 1;
	getline(cin, s);
	for(auto k : s) {
		if( k == ' ') {
			quantity++;
		}
	}
	cout << quantity;
}