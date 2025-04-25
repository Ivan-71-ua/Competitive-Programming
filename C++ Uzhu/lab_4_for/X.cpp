#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	string n;
	cin >> n;
	if(n.find("-") == 0) {
		cout << n.size() - 1;
	}
	else {
		cout << n.size();
	}
}