#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	char ch;
	int k = 0;
	getline(cin, s);
	cin >> ch;
	for (int i = 0; i < s.length(); i++)
	{
		if(isalpha(s[i]) && tolower(s[i]) == ch) {
			k++;
		}
	}
	cout << k;
}