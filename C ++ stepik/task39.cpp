#include <iostream>

using namespace std;

int main() {
	int N, count= 1, function, zero = 0, first = 1;
	cin >> N;
	if ( N == 0) {
		cout << "0";
	}
	else if (N == 1) {
		cout << "1";
	}
	else{
	   while(1) {
		   function = zero + first;
		   zero = first;
		   first = function;
		   count = count + 1;
			if ( N == function) {
				cout << count;
				break;
			}
			if ( N < function) {
				cout << "-1";
				break;
			}
	   }
	   
	}
}