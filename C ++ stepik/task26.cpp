#include <iostream>

using namespace std;

int main() {
   int N, M, X, Y, X2, Y2, n, m;
	cin >> N >> M >> X >> Y;
	if (N > M) {
		X2 = M - X;
		Y2 = N - Y;
		if (X < Y) {
			if (X < X2) {
				if (X < Y2) {
					cout << X;
				}
				else {
					cout << Y2;
				}
			}
			else {
				if (X2 < Y) {
					if ( X2 < Y2) {
						cout << X2;
					}
					else {
						cout << Y2;
					}
				}
				else {
					if (Y < Y2) {
						cout << Y;
					}
					else {
						cout << Y2;
					}
				}
			}
		}
		else {
			if (Y < X2) {
				if (Y < Y2) {
					cout << Y;
				}
				else {
					cout << Y2;
				}
			}
			else {
				if ( X2 < Y2) {
					cout << X2;
				}
				else {
					cout << Y2;
				}
			}
		}
	}
	else {
		N = N + M;
		M = N - M;
		N = N - M;
		X2 = M - X;
		Y2 = N - Y;
		if (X < Y) {
			if (X < X2) {
				if (X < Y2) {
					cout << X;
				}
				else {
					cout << Y2;
				}
			}
			else {
				if (X2 < Y) {
					if ( X2 < Y2) {
						cout << X2;
					}
					else {
						cout << Y2;
					}
				}
				else {
					if (Y < Y2) {
						cout << Y;
					}
					else {
						cout << Y2;
					}
				}
			}
		}
		else {
			if (Y < X2) {
				if (Y < Y2) {
					cout << Y;
				}
				else {
					cout << Y2;
				}
			}
			else {
				if ( X2 < Y2) {
					cout << X2;
				}
				else {
					cout << Y2;
				}
			}
		}
	}
		
}