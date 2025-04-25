#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int q = 0, sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		if (s[i] == '.' && s[i + 1] == '.' || s[i] == '!' && s[i + 1] == '!') {
			continue;
		}
		else if (s[i + 1] == '.' && isalpha(s[i]) || s[i +1] == '?' && isalpha(s[i]) || s[i + 1] == '!' && isalpha(s[i]) || s[i + 1] == ';' && isalpha(s[i]))
			{
				q++;
			}
	}
	cout << q;
}