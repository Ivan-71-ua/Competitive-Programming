#include <bits/stdc++.h>
using namespace std;

void Print_arr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
}
void Add_array(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 20;
	}
	
}
int main() {
	const int SIZES = 10;
	int aray[SIZES];
	Add_array(aray, SIZES);
	Print_arr(aray, SIZES);
}