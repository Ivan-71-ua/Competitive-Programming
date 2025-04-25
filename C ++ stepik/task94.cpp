#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;
	if (s <= "9" && s >= "0") {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}