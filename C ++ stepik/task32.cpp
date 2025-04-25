#include <iostream>

using namespace std;

int main() {
   int N, two = 2;
   cin >> N;
   if (N == 1) {
		cout << "YES";
	}
	else if (N > 1) {
		while (1) {
			if (two == N) {
				cout << "YES";
				break;
			}
			two = two * 2;
			if (two > N) {
				cout << "NO";
				break;
			}
		}
	}
	

}