#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1;
	cin >> s >> s1;
	int k = 0;
	if(s.size() > s1.size()) {
		cout << s << " > "  << s1;
	}
	else if(s.size() < s1.size()) {
		cout << s << " < " << s1;
	}
	else {
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if ((int)s[i] > (int)s1[i]) {
				cout << s << " > "  << s1;
				break;
			}
			else if ((int)s[i] < (int)s1[i]) {
				cout << s << " < "  << s1;
				break;
			}
			else {
				k++;
			}
		}
		if(k == s.size()) {
			cout << s << " = "  << s1;
		}
	}
}