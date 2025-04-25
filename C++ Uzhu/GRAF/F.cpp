#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int t;
	std::cin >> t;
	std::vector<std::vector<int>> maxt_v(t, std::vector<int>(t));
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			std::cin >> maxt_v[i][j];
		}
	}
	bool flag = true;
	for (int i = 0; i < t; i++)
	{
		for (int j = i; j < t; j++)
		{
			if(maxt_v[i][j] != maxt_v[j][i]) {
				flag = false;
				break;
			} if(i == j && maxt_v[i][j] == 1) {
				flag = false;
				break;
			} 
		}
		
	}
	if(flag) {
		std::cout << "YES";
	} else {
		std::cout << "NO"	;
	}
}