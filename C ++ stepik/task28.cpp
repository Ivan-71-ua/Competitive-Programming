#include <iostream>

using namespace std;

int main() {
		int a1, b1, c1, a2, b2, c2;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		//упорядочивание по сторонам первой коробки
		if (a1 > b1) {
			a1 += b1;
			b1 = a1 - b1;
			a1 += -b1;
		}
		if (a1 > c1) {
			a1 += c1;
			c1 = a1 - c1;
			a1 += -c1;
		}
		if (b1 > c1) {
			b1 += c1;
			c1 = b1 - c1;
			b1 += -c1;
		}
		//упорядочивание по сторонам второй коробки
		if (a2 > b2) {
			a2 += b2;
			b2 = a2 - b2;
			a2 += -b2;
		}
		if (a2 > c2) {
			a2 += c2;
			c2 = a2 - c2;
			a2 += -c2;
		}
		if (b2 > c2) {
			b2 += c2;
			c2 = b2 - c2;
			b2 += -c2;
		}
		if (a1 == a2 && b1 == b2 && c1 == c2) {
			cout << "Boxes are equal";
		} else {
			if (a1 <= a2 && b1 <= b2 && c1 <= c2) {
				cout << "The first box is smaller than the second one";
			}
			else {
				if (a1 >= a2 && b1 >= b2 && c1 >= c2) {
					cout << "The first box is larger than the second one";
				}
				else {
					cout << "Boxes are incomparable";
				}
			}
		}
	}
	
