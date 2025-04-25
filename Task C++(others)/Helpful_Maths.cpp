#include <bits/stdc++.h>
using namespace std;


int main() {
	char ch;
	string s;
	getline(cin, s);
	int arr[s.length() - s.length() / 2];
	int k = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i];
		if (ch != '+') {
			arr[k] = (int)ch - 48;
			k++;
		}
	}
	sort(arr, arr + s.length() - s.length() / 2);
	for (int i = 0; i < s.length() - s.length() / 2; i++)
	{
		if(i == s.length() - s.length() / 2 - 1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << "+";
		}
	}
	
}