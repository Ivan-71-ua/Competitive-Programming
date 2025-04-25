#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main() {
	string n;
	cin >> n;
	if (n.find("-") == 0) {
		cout << n[2];
	}
	else {
		cout << n[1];
	}
}