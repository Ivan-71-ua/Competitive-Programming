#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int res = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if(s1[i] != s2[i])
			tmp++;
		else {
			if(tmp > 0) {
				res++;
				tmp = 0;
			}
		}
	}
	if(tmp > 0) {
		res++;
		tmp = 0;
	}
	std::cout << res;
}