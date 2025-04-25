#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1 = "";
	int l = 0;
	cin >> s;
	string h = "hello";
	int k = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if(!(s1.find(s[i]) != string::npos) && s[i] == h[k] || s[i] == 'l' && l == 3) {
			s1 += s[i];
			k++;
			l++;
		}
	}
	if(s1 == "hello") {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}