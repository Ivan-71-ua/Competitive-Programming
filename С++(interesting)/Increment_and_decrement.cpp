#include <iostream>

using namespace std;


/*
Инкремент и декремент
Постфиксный и префиксный
*/

int main() {
	int a = 1, b;
	b = ++a + a++;
	cout << b << endl;
	cout << a << endl;
}