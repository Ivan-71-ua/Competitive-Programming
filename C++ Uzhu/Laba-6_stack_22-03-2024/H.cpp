#include <bits/stdc++.h>

int main( ){
	int n;
	std::cin >> n;
	std::vector<int> soldier(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> soldier[i];
	}
	std::stack<std::pair<int, int>> hight;
	std::vector<int> res(n, -1);
	hight.push({soldier[0], 0});
	for (int i = 1; i < n; i++)
	{
		while(!hight.empty()) {
			int top = hight.top().first;
			if(top > soldier[i]) break;
			hight.pop();
		}
		if(hight.empty()) {
			res[i] = -1;
		} else {
			res[i] = hight.top().second;
		}
		hight.push({soldier[i], i});
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << res[i] << ' ';
	}
	
}