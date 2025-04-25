#include <bits/stdc++.h>
#define Sum(x,y) ((x) + (y)) 
using namespace std;
#define DUBUG 5



int main() {
#ifdef DUBUG
	cout << "DEBUG" << endl;
#endif
	cout << Sum(9, 1) << endl;
#if DUBUG > 10
	cout << "DEBUG" << endl;
#elif DUBUG == 5
	cout << "ALAHA" << endl;
#endif 

}