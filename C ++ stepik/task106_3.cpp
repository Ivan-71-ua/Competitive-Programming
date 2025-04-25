#include <iostream>
#include <string>
#include <set>
using namespace std;
string z(string x) {
	string w = "";
	for (auto y : x) {
		if (y >= 'A' && y <= 'Z') y = y - 'A' + 'a';
		w = w + y;
	}
	return w;
}
int main() {
	int N, k = 0;
	set <string> a, A;
	string c = "";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		a.insert(c);
		A.insert(z(c));
	}
	while (cin >> c){
		if (A.find(z(c)) != A.end() && a.find(c) == a.end()) k++;
		else {
			int u = 0;
			for (auto smv : c) if (smv >= 'A' && smv <= 'Z') u++;
			if (u != 1) k++;
		}
	}
	cout << k;
	return 0;
}