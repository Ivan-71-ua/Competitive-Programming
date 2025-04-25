#include <bits/stdc++.h>
using namespace std;


int main() {
	//sizeof повертає кількість байтів які займає певни змінні чи суму бійтів елементів в масиві
	int arr[]{1, 24, 56, 8};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << endl;
	}
	
}