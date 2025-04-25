#include <iostream>

using namespace std;

int main() {
	int N, min = 2;
	cin >> N;
	while (1) {
		if (N % min == 0) {
			cout << min;
			break;
		}
		else{
			min = min + 1;
			continue;
		}
	}
	
}