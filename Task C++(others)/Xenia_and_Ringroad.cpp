#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	int work[m + 1];
	work[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> work[i];
	}
	long long q_w = 0;
	for (int i = 0; i <= m -1; i++)
	{
		if(work[i]  < work[i + 1] ) {
			q_w += abs(work[i] - work[i + 1]);
		}
		else if(work[i]  > work[i + 1]) {
			q_w += abs((n - work[i]) +	 work[i + 1]);
		}
	}

	cout << q_w;
}