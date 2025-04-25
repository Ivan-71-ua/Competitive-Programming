#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	set<char> a;
	int k = 1;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		char s1 = s[i];
		a.insert(s1);
	}
	if(a.size() % 2 == 0) {
		cout << "CHAT WITH HER!";
	}
	else {
		cout << "IGNORE HIM!";
	}
}