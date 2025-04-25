#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	string fs = "0" , ls = "0" ;
	if(isalnum(s[0])) {
		fs = fs + s[0];
		ls = ls + s[s.size() - 1];
		int f = stoi(fs), l = stoi(ls);
		cout << f + l;
	}
	else {
		fs = fs + s[1];
		ls = ls + s[s.size() - 1];
		int f = stoi(fs), l = stoi(ls);
		cout << f + l;
	}
	
}