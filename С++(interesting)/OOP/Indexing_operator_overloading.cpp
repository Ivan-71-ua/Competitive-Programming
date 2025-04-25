#include <bits/stdc++.h>
using namespace std;

class Aray 
{
public:
	int & operator[] (int index) {
		return arr[index];
	}

private:
	int arr[5] {1, 12, 23, 54, 2};
};

int main() {
	Aray a;
	cout << a[1];
}