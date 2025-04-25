#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int sum = 0;
	string str = "";
	int k = 0;
	char ch;
	for (int i = 0; i < s.size(); i++)
	{
		if(k == 0)
			if(isdigit(s[i])) {
				str = str + s[i];
			}
			else {
				k++;
				sum += stoi(str);
				str = "";
				ch = s[i];
			}
		else {
			if(isdigit(s[i])) {
				str = str + s[i];
				if( i == s.size() - 1) {
					if(ch == '-') {
					sum -= stoi(str);
					str = "";
				}
				else {
					sum += stoi(str);
					str = "";
				}
				}
			}
			else {
				if(ch == '-') {
					sum -= stoi(str);
					str = "";
					ch = s[i];
				}
				else {
					sum += stoi(str);
					str = "";
					ch = s[i];
				}
				
		}
	}
	}
	cout << sum;
}