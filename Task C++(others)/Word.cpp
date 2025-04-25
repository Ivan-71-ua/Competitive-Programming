#include <bits/stdc++.h>
using namespace std;


int main()
{
	string s;
	cin >> s;
	int c = s.length(), k = 0, k2 = 0;
	for (int i = 0; i < c; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') {
			k++;
		}
		else {
			k2++;
		}
	}
	if (k <= k2) {
		for (int i = 0; i < c; i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = 'a' + (s[i] - 'A');
			}
		}
		cout << s;
	} 
	else {
		for (int i = 0; i < c; i++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				s[i] = 'A' + (s[i] - 'a');
			}
		}
		cout << s;
	}
}