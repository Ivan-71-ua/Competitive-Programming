#include <bits/stdc++.h>
#include <fstream>
using namespace std;



int main() {
	string fail_n = "My_fail.txt";
	ofstream fout;
	fout.open(fail_n, ofstream::app);
	if(!(fout.is_open())) {
		cout << "Wrong data";
	}
	else {
		string s;
		cin >> s;
		fout << s;
		fout << "\n";
	}
	fout.close();
}