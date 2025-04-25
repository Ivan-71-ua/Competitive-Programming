#include <bits/stdc++.h>
#define ll long long

int main(){
	ll n, m;
	
	bool ans = true;
	std::cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			std::string s;
			std::cin >> s;
			if(s[0] == 'C' || s[0] == 'M' || s[0] == 'Y') {
				ans = false;
				break;
			}
		}
		if(!ans) break;
	}	
	if(ans)
		std::cout << "#Black&White";
	else
		std::cout << "#Color";
}