#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int sum = 0;
	string str = "0";
	int k = 0;
	char ch;
	if(s.size() == 1) {
		cout << s;
	}
	else {
		for (int i = 0; i < s.size(); i++)
		{
			if(k == 0)
				if(isdigit(s[i])) {
					str = str + s[i];
				}
				else {
					k++;
					sum += stoi(str);
					str = "0";
					ch = s[i];
				}
			else {
				if(isdigit(s[i])) {
					str = str + s[i];
					if( i == s.size() - 1) {
						if(ch == '+') {
						sum += stoi(str);
						str = "0";
					}
					else {
						sum *= stoi(str);
						str = "0";
					}
					}
				}
				else {
					if(ch == '*') {
						sum *= stoi(str);
						str = "0";
						ch = s[i];
					}
					else {
						sum += stoi(str);
						str = "0";
						ch = s[i];
					}
					
			}
		}
		}
		cout << sum;
	}
	
}