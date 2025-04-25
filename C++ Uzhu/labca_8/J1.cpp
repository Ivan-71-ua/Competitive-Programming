#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int k = 0, l = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if(k == 0 && s[i] == '-') {
			k++;
			cout << endl;
		}
		else if(l == 0 && s[i] == '_') {
			cout << endl;
			l++;
		}
		else {
			cout << s[i];
		}
	}
	
}