#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	char arr[12] {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};
	for (int i = 0; i < s.length(); i++)
	{
		bool is = false;
		for (int j = 0; j < 12; j++) {
			if(s[i] == arr[j]) {
				is = true;
			}
		}
		if(!is) {
			if(s[i] >= 'A' && s[i] <= 'Z' ) {
				char ch = 'a' + (s[i] - 'A');
				cout << "." << ch;
			}
			else {
				cout << "." << s[i];
			}
		}
		is = false;
	}
	
}