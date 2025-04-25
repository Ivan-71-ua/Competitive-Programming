#include <iostream>

using namespace std;

int main() {
	char c;
	int a, b;
	cin >> c;

	switch (c) {
		case '-':
			cin >> a >> b;
			cout << a - b;
			break;
		case '+':
		{
			cin >> a >> b;
			cout << a + b;
			break;
		}
		default:
			cout << "You have only two actions \"+\" or \"-\"";
			break;
	}
	system("pause");
}