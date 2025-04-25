#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int k = 1;
	int c = s.length();
	for (int i = 0; i < c - 1; i++)
	{
		if(s[i] == s[i + 1]) {
			k++;
		}
		if(k >=7) {
			cout << "YES";
			break;
		}
		if(s[i] != s[i + 1]) {
			k = 1;
		}
	}
	if (k < 7) {
		cout << "NO";
	}
}