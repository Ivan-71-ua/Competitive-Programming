#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1, s2;
	cin >> s >> s1 >> s2;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == s1[0]) {
			s[i] = s2[0];
		}
	}
	string k = "0";
	k = k + s;
	cout << stoi(k);
}