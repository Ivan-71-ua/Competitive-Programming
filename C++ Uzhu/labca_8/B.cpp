#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' || s[i] == 'I' || s[i] == 'E') {
			n++;
		}
	}
	cout << n;
}