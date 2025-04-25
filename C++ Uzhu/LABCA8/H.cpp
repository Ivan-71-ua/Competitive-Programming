#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
			cout << s[i] << s[i];
		}
		else {
			cout << s[i];
		}
	}
	
}