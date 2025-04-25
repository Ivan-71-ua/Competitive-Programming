#include <bits/stdc++.h>
using namespace std;



int main() {
	
	const int SIZE = 5;
	int arr[SIZE]{5, 8, 9, 99, 2};
	int *parr = arr;
	for (int i = 0; i < SIZE; i++)
	{
		cout << parr[i] << endl;
	}
	cout << "arr\t" << arr << endl;
	cout << "parr\t" << parr << endl;
	cout << "_______";
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(arr + i) << endl;
	}
	
	
}
