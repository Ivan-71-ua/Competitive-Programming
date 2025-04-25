#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset <int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (s.find(x) == s.end()) { cout << "NO" << endl; }
		else cout << "YES" << endl;
		s.insert(x);
	}
	
	return 0;
}