#include <bits/stdc++.h>
using namespace std;


int main() {
	// тип_даних ім'я [кількість елементів]
	// ініцілізація №1
	int arr[4];
	arr[0] = 4;
	arr[1] = 6;
	arr[2] = 1;
	arr[3] = 0;
	// arr[4] = 9 - error
	// cout << arr [10]; - error(randome number)
	// ініцілізація №2
	int arr1[4]{1, 2, 4, 7};
	int arr2[4]{};
	int arr3[]{1, 2, 4, 7};
	int arr4[4]{1, 4}; // [2],[3] == 0
	// цикл +  масив
	const int size = 5;
	int arr5[5];
	for (int i = 0; i < size; i++)
	{
		arr5[i] = i;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr5[i] << endl;
	}
	int p[5];
}