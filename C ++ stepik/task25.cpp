#include <iostream>

using namespace std;

int main() {
   int N, M, K, sqv, sqv_h, sqv_l;
	cin >> N >> M >> K;
	sqv = N * M;
	if (K > sqv) {
		cout << "NO";
	}
	else if ( K % N == 0|| K % M == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}