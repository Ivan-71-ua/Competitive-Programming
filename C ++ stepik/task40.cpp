#include <iostream>

using namespace std;

int main() {
	int numbers, max = 0, times = 0;
	while (cin >> numbers && numbers != 0) {
		if (max < numbers) {
			max = numbers;
			times = 1;
		}
		else if (max == numbers) {
			times += 1;
		}
	}
	cout << times;
}