#include <bits/stdc++.h>

bool is = true;

void DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, int &ver, int cur) {
	used[k] = true;
	if(!is)
		return;
	for (auto now: v[k])
	{
		if(now != cur) {
			if(!used[now]) {
				ver++;
				DFS(now, v, used, ver, k);
			} else {
				is = false;
				DFS(now, v, used, ver, k);
			}
		} 
	}
}

int main() {
	int n;
	int cur = -1;
	std::cin >> n;
	std::vector<std::vector<int>> v(n);
	std::vector<bool> used(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			std::cin >> tmp;
			if(tmp == 1)
				v[i].push_back(j);
		}
	}
	
	int ver = 1;
	DFS(0, v, used, ver, cur);
	if(ver == n && is) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}