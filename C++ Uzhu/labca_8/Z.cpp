#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == '3' || s[i] == '9') {
			continue;
		}
		else {
			cout << s[i];
		}
	}
	
	
}