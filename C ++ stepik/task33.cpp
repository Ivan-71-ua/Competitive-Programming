#include <iostream>

using namespace std;

int main() {
	int numbers, count = 0;
	cin >> numbers;
	while (numbers != 0) {
		count = count + 1;
		cin >> numbers;
	}
	cout << count;
}