#include <iostream>

using namespace std;

int main() {
	int N, min = 1;
	cin >> N;
	while (min * min <= N) {
		cout << min * min << " ";
		min = min + 1;
	}
}