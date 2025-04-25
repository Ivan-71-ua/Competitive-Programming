#include <iostream>
#include <set>
#include<map>
#include <string>

using namespace std;

int main() {
	map<string, string> key;
	int n;
	cin >> n;
	while(n--) {
		string s, s1;
		cin >> s >> s1;
		key[s] = s1;
	}
	string s;
	cin >> s;
	for(auto now : key) {
		if(now.first == s) {
			cout << now.second;
		}
		else if(now.second == s) {
			cout << now.first;
		}
	}
}