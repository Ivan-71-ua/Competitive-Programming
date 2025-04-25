#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
using namespace std;


int main() {
	set<int> num;
	int n, x;
	cin >> n;
	while(n--) {
		cin >> x;
		if((num.insert(x)).second == true) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	
}