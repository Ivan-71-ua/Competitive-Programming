#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max = *max_element(arr, arr + n);
	int min = *min_element(arr, arr + n);
	if(arr[0] ==  max && arr[n-1] == min) {
		cout << 0;
	}
	else {
		int k, k1;
		for (int i = n -1; i >= 0; i--)
		{
			if(arr[i] == min) {
				k = i;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if(arr[i] == max) {
				k1 = i;
				break;
			}
		}
		if(arr[k]==arr[k1]){cout<<0<<endl;}
      else if(k>k1){cout<<abs(0-k1)+abs((n-1)-k)<<endl;}
      else{cout<<(abs(0-k1)+abs((n-1)-k))-1<<endl;}
	}
}