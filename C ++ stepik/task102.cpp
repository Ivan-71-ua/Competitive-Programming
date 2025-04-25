#include <iostream>
#include <set>

using namespace std;

int main() {
	set <int> num;
	set <int> num1;
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
		num1.insert(c);
	}
	for(auto now : num) {
		for (auto now1: num1) {
			if (now == now1) {
				k++;
			}
		}
	}
	cout << k;
}