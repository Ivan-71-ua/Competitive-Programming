#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


int main() {
	string s;
	string s1;
	vector<string> str;
	while(cin >> s) {
		if (s1.empty() || s1.length() < s.length()) {
			s1 = s;
		}
	}
	cout << s1;
}