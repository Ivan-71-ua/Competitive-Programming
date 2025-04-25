	#include <bits/stdc++.h>
	using namespace std;


	int main() {
		int m;
		cin >> m;
		string yes = "yes";
		for (int i = 0; i < m; i++)
		{
			string s;
			cin >> s;
			for (int i = 0; i < 3; i++)
			{
				if(isupper(s[i])) {
					s[i] = tolower(s[i]);
				}
			}
			if(s == yes) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		
		}
	}