#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 1;
	while(n--) {
		while(1) {
			if(k % 2 != 0 && k % 3 != 0 && k % 5 != 0) {
				cout << k << " ";
				k++;
				break;
			}
			k++;
		}
		
	}
}