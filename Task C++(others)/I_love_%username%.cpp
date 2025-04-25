#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	cin >> n;
	int balls[n];
	int q = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> balls[i];
	}
	int min = balls[0], max = balls[0];
	for (int i = 1; i < n; i++)
	{
		if(balls[i] < min) {
			q++;
			min = balls[i];
		}
		else if(max < balls[i]) {
			q++;
			max = balls[i];
		}
	}
	cout << q;
}