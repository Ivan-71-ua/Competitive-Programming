#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, s1;
	cin >> s >> s1;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i] != s1[i]) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	
} 	