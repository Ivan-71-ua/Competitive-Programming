#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	string n;
	cin >> n;
	for (int i = n.size() - 1; i >= 0; i--) {
		cout << n[i];
	}
}