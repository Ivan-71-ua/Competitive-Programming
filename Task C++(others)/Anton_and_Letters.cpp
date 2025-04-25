#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
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
	cout << a;
}