#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


int main() {
	string s;
	int temp = 0;
	cin >> s;

	if (s.size() % 2 == 0) {
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				temp++;
			}
		}
	}
	else {
		for (int i = 0; i < (s.size() - 1) / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				temp++;
			}
		}
	}
	if (temp == 0) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}