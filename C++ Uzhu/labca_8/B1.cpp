#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if(i == 0 || s[i-1] == ' ') {
			s[i] = toupper(s[i]);
			cout << s[i];
		}
		else {
			cout << s[i];
		}
	}
}