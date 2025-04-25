#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, s1;
	cin >> s >> s1;
	int c = s.length();
	bool is = true;
	for (int i = 0, j = c - 1; i < c, j >= 0 ; i++, j--)
	{
		if(s[i] != s1[j]) {
			is = false;
			break;
		}
	}
	if(!is) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
} 	