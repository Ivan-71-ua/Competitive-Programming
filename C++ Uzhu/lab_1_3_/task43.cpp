#include <iostream>
#include <cmath>
#include<string>
using namespace std;

int main() {
	string n,a;
	cin >> n;
	cin >> a;
	int k = n.length();
	int c = 0;
	while(k--) {
		string s;
		s = n[k];
		if(s == a) {
			c++;
		}
	}
	cout << c;
}