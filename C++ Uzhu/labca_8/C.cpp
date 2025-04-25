#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	while(getline(cin, s)) {
		int com = -1;
		for (int i = 0; i < s.size() ; i++)
		{
			if(s[i] == '/' && s[i + 1] == '/') {
				com = 1;
			}
			if(s[i] == '-' && s[i + 1] == '>' && com != 1) {
				cout << '.';
				i++;
			}
			else {
				cout << s[i];
			}
		}
		cout << endl;
	}
}