#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int k = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if((ispunct(s[i])) ) {
			k++;
		}
	}
	cout << k;
}