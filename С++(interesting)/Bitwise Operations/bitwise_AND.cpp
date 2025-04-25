#include <bits/stdc++.h>
using namespace std;


int main() {
	unsigned char flags = 5; // двійкова 00000101, 1 буде виключений
	unsigned char mask = 4; // двійкова 00000100
	if((flags&mask) == mask) {
		cout << "2 bits of the number are on";
	}
	else {
		cout << "2 bits of the number are off";
	}
}
/*

*/