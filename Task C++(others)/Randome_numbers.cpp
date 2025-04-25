#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(NULL));
	const int SIZE = 10;
	int arr[SIZE];
	bool alreadyThere;
	for (int i = 0; i < SIZE; )
	{
		alreadyThere = false;
		int newElement = rand() % 20;
		for (int j = 0; j < i; j++ ) {
			if (arr[j] == newElement) {
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere) {
			arr[i] = newElement;
			i++;
		}
	}
	for(auto now : arr) {
		cout << now << endl;
	}
	
}