#include <iostream>

using namespace std;

int main() {
	int numbers, min;
	cin >> numbers;
	min = numbers;
	while ( numbers != 0) {
		if (numbers > min) {
			min = numbers;
		}
		cin >> numbers;
	}
	cout << min;
}