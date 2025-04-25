#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	string c = "";
	int k = 0;
	cin >> s;
	for (int i = 0; i < s.length() + 1; i++) {
		char c2 = s[i];
		if (c2 >= 'a' && c2 <= 'z' || c2 >= 'A' && c2 <= 'Z') {
			k = 100;
			continue;
		}
		if(c2 == '.' || i == s.length()) {
			if(c.empty()) {
				k = 100;
				continue;
			}
			if(c.length() > 3) {
				k = 100;
				continue;
			}
			
			int c1 = stoi(c);
			if (0 <=	c1 && c1 <= 255) {
				k++;
				c = "";
				continue;
			}
		}
		if(c2 <= '0' && c2 >= '9') {
			k = 100;
			continue;
		}
		c = c + s[i];
	}
	if(k == 4) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}