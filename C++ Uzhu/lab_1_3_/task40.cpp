#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int a, a1;
	cin >> n;
	cin >> a;
	n--;
	while(n--) {
		cin >> a1;
		if (0 > a && 0 > a1 || a > 0 && a1 > 0) {
			cout << a << " " << a1 << endl;
		}
		a = a1;
	}
		

}