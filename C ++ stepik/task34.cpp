#include <iostream>

using namespace std;

int main() {
	int numbers, sum = 0;
	cin >> numbers;
	while (numbers != 0) {
		sum = sum + numbers;
		cin >> numbers;
	}
	cout << sum;
}