#include <bits/stdc++.h>
using namespace std;


class My_class
{
	int *date;
public:
My_class(int size) {
	date = new int[size];
	for (int i = 0; i < size; i++)
	{
		date[i] = i;
	}

	cout << "A1\n";
}
~My_class() {
	delete[] date;
	cout << "Z0\n";
}
};

void foo() {
	cout << "Start\n";
	My_class Bee(5);
	cout << "Finish\n";
}
int main() {

	foo();
}