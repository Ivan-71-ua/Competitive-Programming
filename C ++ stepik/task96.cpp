#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	char s;
	cin >> s;
	if (s >= 'a' && s <= 'z') {
		s = 'A' + (s - 'a');
		cout << s;
		}
	else if (s >= 'A' && s <= 'Z') {
		s = 'a' + (s - 'A');
		cout << s;
	}
	else {
		cout << s;
	}
}