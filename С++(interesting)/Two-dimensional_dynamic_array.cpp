#include <bits/stdc++.h>
using namespace std;


int main() {
	int x, y;
	cin >> x >> y;
	int **arr = new int *[x];
	for (int i = 0; i < x; i++)
	{
		arr[i] = new int[y];
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}



	for (int i = 0; i < x; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}