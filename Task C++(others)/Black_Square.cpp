#include <bits/stdc++.h>
#define ll long long
#define db double




int main() {
	std::string st;
	int a, b, c, d, sum = 0;
	std::cin >> a >> b >> c >> d >> st;
	for (int i = 0; i < st.size(); i++)
	{
		if(st[i] == '1') {
			sum += a;
		}
		else if(st[i] == '2') {
			sum += b;
		}
		else if(st[i] == '3') {
			sum += c;
		}
		else if(st[i] == '4') {
			sum += d;
		}
	}
	std::cout << sum;
}