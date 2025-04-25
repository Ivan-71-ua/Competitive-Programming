#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	int arr[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = max;
			max++;
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}