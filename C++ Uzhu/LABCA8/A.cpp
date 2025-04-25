#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int k = 0;
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if(isdigit(s[i]) && s[i +1] == '+'|| isdigit(s[i]) && s[i+1] == '-' || isdigit(s[i]) && s[i+1] == '*' || isalpha(s[i]) && s[i +1] == '+'|| isalpha(s[i]) && s[i+1] == '-' || isalpha(s[i]) && s[i+1] == '*') {
			k++;
		}
	}
	cout << k;
}