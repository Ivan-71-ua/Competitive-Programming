#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		string s = "GCV";
		for (int i = 0; i < a; i++)
		{
			swap(s[1],s[2]);
			swap(s[1],s[0]);
		}
		cout << s << endl;
	}

}	