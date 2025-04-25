#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> num;
	set<int> num1;
	int n, a;
	cin >> n;
	while(n--) {
		int c;
		cin >> c;
		num.insert(c);
	}
	cin >> a;
	while(a--) {
		int c;
		cin >> c;
		if ((num.insert(c)).second == false) {
			num1.insert(c);
		}
	}
	for(auto now : num1) {
		cout << now << " ";
	}
}