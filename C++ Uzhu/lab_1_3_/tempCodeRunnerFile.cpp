#include <iostream>
#include <cmath>
#include<string>
using namespace std;

int main() {
	string n;
	cin >> n;
	int k = n.length() - 1;
	while(k--) {
		cout << n[k];
	}
}