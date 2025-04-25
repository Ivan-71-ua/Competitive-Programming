#include <bits/stdc++.h>
#include <fstream>
using namespace std;



int main() {
	string fail_n = "My_fail.txt";
	ifstream fin;
	fin.open(fail_n);
	if(!(fin.is_open())) {
		cout << "Wrong data";
	}
	else {
		string str;
		while(!fin.eof()) {
			str = "";
			// fin.get(char)
			//fin >> str
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}