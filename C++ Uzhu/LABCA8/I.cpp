#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if(isalpha(s[i])) {
			cout << s[i] << s[i];
		}
		else {
			cout << s[i];
		}
	}
	
}