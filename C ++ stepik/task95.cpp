#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;
	if (s >= "a" && s <= "z") {
		char c = s[0];
		int temp = c - 'a';
		c = 'A' + temp;
		string s2 = "";
		s2 = +c;
		cout << s2;
		}
	else {
		cout << s;
	}
}