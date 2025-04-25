#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		cout << s[0];
		for (int i = 1; i < s.size() - 2; i++)
		{
			if(i % 2 != 0) {
				cout << s[i];
			}
		}
		cout << s[s.size() - 1];
		cout << endl;
	}
	
}