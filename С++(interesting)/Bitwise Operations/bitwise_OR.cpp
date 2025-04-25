#include <bits/stdc++.h>
using namespace std;


int main() {
	unsigned char flags = 8; // двійкова 00001000
	unsigned char mask = 5; // двійкова 00000101
	flags = flags | mask; // двійкова 00001101
	cout << (int)flags << endl;
}