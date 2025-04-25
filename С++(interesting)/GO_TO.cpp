#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "One\n";

	goto there;

	cout << "Two\n";
	cout << "Three\n";

	there:

	cout << "Four\n";
	cout << "Five\n";
}