#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, l;
	cin >> n >> l;
	int lights[n];
	for (int i = 0; i < n; i++)
	{
		cin >> lights[i];
	}
	sort(lights, lights + n);
	double max_d = -1;
	for (int i = 1; i < n; i++)
	{
		if(lights[i] - lights[i -1] > max_d) {
			max_d = lights[i] - lights[i - 1];
		}
	}
	max_d /= 2;
	double l_d = l - lights[n - 1], s_d = lights[0];
	cout << fixed << setprecision(9);	
	cout << (max(max(max_d, s_d), l_d));
}