#include <bits/stdc++.h>


int main () {
	int t;
	std::cin >> t;
	std::set<int> arr;
	for (int i = 0; i < t; i++)
	{
		int tp;
		std::cin >> tp;
		arr.insert(tp);
	}
	std::vector<int> ass(arr.begin(), arr.end());
	if(t % 2 == 0) {
		for (int i = ass.size() -1; i >= 0; i--)
		{
			std::cout << ass[i] << '\n';
		}
	} else {
		for (int i = 0; i < ass.size(); i++)
		{
			std::cout << ass[i] << '\n';
		}
	}
	
}