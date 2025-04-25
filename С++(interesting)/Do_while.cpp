#include <iostream>

using namespace std;

/* Написать программу, которая находит сумму всех целых нечетных чисел в диапазоне, указанном пользователе.*/

int main()
{
	int sum = 0;
	int rangeBegin, rangeEnd;
	cout << "Enter the start of the range." << endl;
	cin >> rangeBegin;
	cout << "Enter the end of the range." << endl;
	cin >> rangeEnd;
	do
	{
	if (rangeBegin % 2 != 0)
	{
	sum += rangeBegin;
	}
	rangeBegin++;
	} while (rangeBegin<=rangeEnd);
	cout << "Sum of all odd integers in the specified range = " << sum << endl;

}