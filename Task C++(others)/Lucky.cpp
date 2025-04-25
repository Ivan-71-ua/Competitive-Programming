#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		if((int)s[0] + (int)s[1] + (int)s[2] == (int)s[3] +(int)s[4] +(int)s[5]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
}