#include <bits/stdc++.h>
using namespace std;


int main() {
	int k = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i] <= 'Z' && s[i] >= 'A') {
			k++;
		}
	}
	if (k == s.length() || k == s.length() - 1 && s[0] >= 'a' && s[0] <= 'z') {
		for (int i = 0; i < s.length(); i++) {
			if(s[i] <= 'Z' && s[i] >= 'A') {
				s[i] = 'a' + (s[i] - 'A');
			}
			else {
				s[i] = 'A' + (s[i] - 'a');
			}
		}
	}
	cout << s;
}