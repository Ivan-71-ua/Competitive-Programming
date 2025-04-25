#include <iostream>

using namespace std;

int main() {
	int numbers, first = 0, two = 0, three = 0, times = 0;
	cin >> numbers;
	first = numbers;
	cin >> numbers;
	two = numbers;
	cin >> numbers;
	three = numbers;
	while (numbers != 0) {
		if (first < two && three < two) {
			++times;
		}
		first = two;
		two = three;
		cin >> numbers;
		three = numbers;
   }
	cout << times;
}