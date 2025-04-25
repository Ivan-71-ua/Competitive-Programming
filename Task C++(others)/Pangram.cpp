#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if(s[i] <= 'Z' && s[i] >= 'A') {
			s[i] = 'a' + (s[i] - 'A');
		}
	}
	int a = 0;
	char ch = 'a';
	for (int i = 0; i < 26; i++)
	{
		if(s.find(ch) != string::npos) {
			a++;
			ch++;
		}
		else{
			ch++;
		}
	}
	if(a == 26) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}