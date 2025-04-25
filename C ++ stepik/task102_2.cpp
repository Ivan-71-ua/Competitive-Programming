#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> num;
	int n, a;
	int k = 0;
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
		if((num.insert(c)).second == false) {
			k++;
		}
	}
		
	cout << k;
}