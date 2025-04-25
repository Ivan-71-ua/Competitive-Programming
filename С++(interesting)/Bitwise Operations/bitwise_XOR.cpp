#include <bits/stdc++.h>
using namespace std;


int main() {
	unsigned char flags = 9; // двійкова 00001001
	unsigned char mask = 1; // двійкова 00000001
	flags = flags ^ mask; // двійкова 00001000 (8)
	cout << (int)flags << endl;
	flags ^= mask; // двійкова 00001001 (9)
	cout << (int)flags << endl;
}