#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int k = 0, k_max = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'k') {
			k++;
		}
		else {
			if(k_max < k)
				k_max = k;
			k = 0;
		}
	}
	if(k_max < k)
				k_max = k;
	cout << k_max;
}