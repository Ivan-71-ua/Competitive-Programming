#include <bits/stdc++.h>
#include <fstream>
using namespace std;



int main() {
	fstream fs;
	fs.open("fstrim.txt", fstream::in | fstream::out | fstream::app);
	if(!fs.is_open()) {
		cout << "somethig wromg";
	}
	else {
		string s;
		int val;
		cin >> val;
		if(val == 1) {
			cin >> s;
			fs << s << "\n";
		}
		else if (val == 2) {
			while (!fs.eof()) {
				s = "";
				fs >> s;
				cout << s << endl;
			}
		}
	}
	fs.close();
}