


#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f, g, h, i;
	
	// Введення елементів матриці
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
	
	// Обчислення детермінанта
	int determinant = a * e * i + b * f * g + c * d * h 
						- c * e * g - b * d * i - a * f * h;
	
	// Виведення результату
	cout << determinant;
	
	return 0;
}
