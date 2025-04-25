#include <bits/stdc++.h>
#define ll long long
#define db double

int main()  {
	std::string st;
	std::cin >> st;
	int sum = 0;
	char point = 'a';
	for (int i = 0; i < st.size(); i++)
	{
		if(point != st[i]) {
			sum += std::min(abs(point - st[i]), 26 - abs(point - st[i]));
			point = st[i];
		}
	}
	std::cout << sum;
	
}