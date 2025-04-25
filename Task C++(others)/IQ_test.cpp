#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int dob = 0, n_dob = 0, q_dob = 0, q_n_dob = 0;
	for (int i = 0; i < n; i++)
	{
		if(arr[i] % 2 == 0) {
			dob = i;
			q_dob++;
		}
		else {
			n_dob = i;
			q_n_dob++;
		}
	}
	if(q_dob == 1) {
		cout << dob + 1;
	}
	else {
		cout << n_dob + 1;
	}
}