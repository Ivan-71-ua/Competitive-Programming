#include <bits/stdc++.h>


int main() {
	std::string s;
	std::cin >> s;
	int prev = -1;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'A'|| s[i] == 'E'|| s[i]== 'I'|| s[i]=='O'|| s[i] == 'U' || s[i] == 'Y') {	
			res = std::max(res, i - prev);
			prev = i;
		}
	}
	res = std::max(res, (int)s.size() - prev);
	std::cout << res;
}