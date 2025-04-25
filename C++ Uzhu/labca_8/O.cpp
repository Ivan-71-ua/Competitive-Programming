#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int k;
	cin >> s >> k;
	for (int i = 0; i < s.size(); i++)
	{
		char l = s[i];
		if(l - k < 65) {
			char q = 90 - (65 - (l - k)) + 1;
			cout << q;
		}
		else {
			char ch = s[i] - k;
			cout << ch;
		}
	}
	
}