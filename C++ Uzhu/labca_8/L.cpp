#include <bits/stdc++.h>
using namespace std;


int main() {	
	string s, s1;
	while (cin >> s && cin >> s1) {
		sort(s.begin(), s.end());
		sort(s1.begin(), s1.end());
		char ch = 'a';
		for (int i = 0; i < 26; i++)
		{
			int k = count(s.begin(), s.end(), ch);
			int k1 = count(s1.begin(), s1.end(), ch);
			if( k == 0 || k1 == 0) {
			ch++;
			}
			else if (k == 1 || k1 == 1) {
				cout << ch;
				ch++;
			}
			else {
				int m = min(k, k1);
				for (int i = 0; i < m; i++)
				{
					cout << ch;
				}
				ch++;
				}
		}
		cout << endl;
	}
}