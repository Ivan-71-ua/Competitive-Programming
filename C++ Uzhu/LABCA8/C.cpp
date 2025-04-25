#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int k = -1;
	int k1 = -1;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i] ==  'f' || s[i] == 'F') {
			k = i;
			break;
		}
	}
	for (int j = s.length(); j >= 0; j--)
	{
		if(s[j] ==  'f' || s[j] == 'F') {
			k1 = j;
			break;
		}
	}
	if(k1 == k && k != -1) {
		cout << k;
	}
	else if(k1 != 0 && k1 != 0 && k1 != k) {
		cout << k << ' ' << k1;
	}

}