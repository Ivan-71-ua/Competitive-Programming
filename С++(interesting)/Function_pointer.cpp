#include <bits/stdc++.h>
using namespace std;

string GetDateFromBD() {
	return "Date from BD";
}
string GetDateFromWeb() {
	return "Date from WED";
}
string GetDateFromAstral(){
	return "Date from astral";
}

void ShowInfo( string(*date)()) {
	cout << date() << endl;
}

int main() {
	ShowInfo(GetDateFromBD);
	ShowInfo(GetDateFromWeb);
	ShowInfo(GetDateFromAstral);
}