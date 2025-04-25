#include <iostream>

using namespace std;

int main() {
	int numbers, first = 0, two = 0, three = 0, times = 0, distanse1 = 0, distanse2 = 0, demo_distanse = 1, finish = 1;
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
		if (times > 0) {
			++demo_distanse;
		}
		if (times >= 2) {
			distanse1 = demo_distanse;
			if (distanse2 == 0) {
				distanse2 = distanse1;
			}
			if (distanse2 > distanse1) {
				distanse2 = distanse1;
			}
			distanse1 = 0;
			
			demo_distanse = 1;
			finish += times;
			times = 1;
			if (finish == 1) {
				distanse2 = 0;
			}
		}
		
		first = two;
		two = three;
		cin >> numbers;
		three = numbers;
	}
	cout << distanse2;
}
