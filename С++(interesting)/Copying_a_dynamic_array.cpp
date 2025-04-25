#include <bits/stdc++.h>
using namespace std;


void FillArray(int* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	
}
void ShowArray(const int* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}


int main() {
	int size = 10;
	int *firstarray = new int[size];
	int *secondarray = new int[size];
	FillArray(firstarray, size);
	FillArray(secondarray, size);
	ShowArray(firstarray, size);
	ShowArray(secondarray, size);
	cout << "====================\n";
	delete[] secondarray;
	secondarray = new int[size];
	for (int i = 0; i < size; i++)
	{
		secondarray[i] = firstarray[i];
	}
	ShowArray(firstarray, size);
	ShowArray(secondarray, size);

	delete[] firstarray;
	delete[] secondarray;
}