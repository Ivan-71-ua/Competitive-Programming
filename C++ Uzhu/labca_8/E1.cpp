#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, l = "#$%!&'()*+,-./:;<=]>?@[^_`{|}~";
	getline(cin, s);
	int k = 0;
	for(int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < l.size(); j++) {
			if(s[i] == l[j]) {
				k++;
			}
		}
			if (s[i] == '"' || s[i] == 92)
			{
				k++;
			}
	}
	cout << k;
}