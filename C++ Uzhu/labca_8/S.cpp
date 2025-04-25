#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if(isdigit(s[i])) {
			if(s[i] == '9') {
				cout << 0;
			}
			else {
				char ch = s[i] + 1;
				cout << ch;
			}
		}
		else {
				cout << s[i];
			}
	}
	
}