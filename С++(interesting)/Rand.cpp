#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(NULL)); // точка відліку для алгоритму рандомного числа, time повестає реальний час
	int const SIZE = 10;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100 + 15; // двоцифрові числа, починаючи від 15
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i]  << endl;
	}
}